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

##def makeAll():
##    least = {}
##    for i in range(1,16):
##        findLeast(i,least)
##    return least

def makeAll2():
    least = {}
    for i in range(1,5):
        findLeast(i,least)
    return least

ref = makeAll2()
    
def eff(s):
    k = len(s)
    if k < 5:
        return ref[s]
    if s[k-1] == '+':
        return eff(s[:k-1])
    else:
        if s[0] == '-':
            return 1 + eff(flip(s[1:],k-1))
        else:
            last = k-1
            for i in range(k):
                if s[i] == '-':
                    last = i
                    break
            return 2 + eff(flip(s[i:], k-i))
    
    

f = open('a.in', 'r')
g = open('a.out', 'w')

t = int(f.readline())
#least = makeAll2()
##
for i in range(1,t+1):
    pan = f.readline().split('\n')[0]
    ans = eff(pan)
    pr = "Case #"+str(i)+ ": " + str(ans)
    print pr
    g.write(pr + '\n')


f.close()
g.close()
