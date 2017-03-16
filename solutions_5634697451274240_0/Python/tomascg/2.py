def sign(c):
    if c == '+':
        return '-'
    else:
        return '+'

def flip(s,i):
    ss = [x for x in s]
    for j in range(i):
        try:
            ss[j] = sign(s[i-1-j])
        except:
            print s, i, j, ss
    return "".join(ss)
    

def good(symbol,j):
    return symbol == j*'+'

def findLeast(k,least):
    st = k*'+'
    least[st]=0
    curr = [st]
    count = 1
    while(count < 2**k):
        x = curr.pop(0)
        for i in range(1,k+1):
            mod = flip(x,i)
            if not mod in least:
                least[mod] = least[x] + 1
                count += 1
                curr.append(mod)
                
    return least

def makeAll():
    least = {}
    for i in range(1,11):
        findLeast(i,least)
    return least
    
    
    

f = open('a.in', 'r')
g = open('a.out', 'w')

t = int(f.readline())
least = makeAll()

for i in range(1,t+1):
    pan = f.readline().split('\n')[0]
    ans = least[pan]
    pr = "Case #"+str(i)+ ": " + str(ans)
    print pr
    g.write(pr + '\n')


f.close()
g.close()
