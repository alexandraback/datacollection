from math import log

def delim(line,ch):
    items = []
    item = ''
    for c in line:
        if c != ch:
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

    
def gcd(a,b):
    if (a<b):
        a,b = b,a
    r = 1
    while r != 0:
        r = a%b
        a = b
        b = r
    return a
   

def solve(p,q):
    g = gcd(p,q)
    p = p/g
    q = q/g
    if p == 1 and q == 1:
        return "0"
    n = 1
    while True:
        if n == q:
            break
        elif n > q:
            return "impossible"
        else:
            n = n*2
    f = p/q
    low = 0
    high = 1
    count = 0
    while True:
        count += 1
        mid = (low+high)/2
        if mid <= f:
            return str(count)
        else:
            high = mid
    
 


f = open("A-large.in",'r')
outf = open('probAlarge.txt','w')

lines = f.readlines()
T = int(lines[0]) #number of cases
caseIndex = 1;
for i in range(T):
    line = lines[caseIndex]
    l = strListToInt(delim(line,'/'))
    p = l[0]
    q = l[1]
    
    
    

    caseIndex += 1
    outf.write("Case #" + str(i+1) + ": " + solve(p,q) + "\n")
    

outf.close()
