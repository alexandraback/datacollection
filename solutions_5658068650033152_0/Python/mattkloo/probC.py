from math import ceil,sqrt

def delim(line):
    items = []
    item = ''
    for c in line:
        if c != ' ':
            item += c
        else:
            items.append(item)
            item = ''
    items.append(item[:-1])
    return items

def strListToInt(items):

    for i in range(len(items)):
        items[i] = int(items[i])
    return items
    

def solve(N,M,K):
    if K==1:
        return '1'
    L = min(N,M)
    H = max(N,M)

    
    n = ceil( (2+sqrt(4-8*(1-K)))/4 )
    if 2*n-1<=L:
        return str(4*(n-1))
    n = ceil( (-2+sqrt(4+8*K))/4)
    if 2*n <= L:
        return str(4*n)
    
    if L%2 == 1:
        n = (L+1)//2
        enclosed = 2*n*(n-1)+1
        stones = 4*(n-1)
    else:
        n = L//2
        enclosed = 2*n*(n+1)
        stones = 4*n
    
    rows = L
    cols = L
    left = True
    while True:
        
        if cols<H:
            cols +=1
        elif rows%2  == 1 and left:
            left = False
            rows -= 1
        elif rows%2 == 0 and left:
            left = False
            rows -= 2
        else:
            left = True
        enclosed += rows
        if L==1:
            stones += 1
        else:
            stones += 2
        if enclosed >= K:
            return str(stones-(enclosed-K))
            

 


f = open("C-small-attempt4.in",'r')
outf = open('probCsmall.txt','w')

lines = f.readlines()
T = int(lines[0]) #number of cases
caseIndex = 1;
for i in range(T):
    line = lines[caseIndex]
    items = strListToInt(delim(line))
    N = items[0]
    M = items[1]
    K = items[2]
    

    caseIndex += 1
    outf.write("Case #" + str(i+1) + ": " + solve(N,M,K) + "\n")
    

outf.close()
