
import math

def find(low,high,oddlow,oddhigh):
    ilow, ihigh = int(low), int(high)
    if oddhigh:
         j = high[:-1] + high[::-1]
    else:
         j = high + high[::-1]
    if oddlow:
         i = low[:-1] + low[::-1]
    else:
         i = low + low[::-1]
    while int(i) <= int(j):
        yield int(i)
        ilow += 1
        nlow = str(ilow)
        if len(nlow) > len(low):
            if oddlow:
                low = nlow[:-1]
                ilow = int (low)
                oddlow = False
            else:
                low = nlow
                oddlow = True
        else:
            low = nlow
        if oddlow:
             i = low[:-1] + low[::-1]
        else:
             i = low + low[::-1]
        
    

def isp(s):
    if len(s) <= 1:
        return True
    if s[0] != s[-1]:
        return False
    return isp(s[1:-1])

def solve(filename):
    f = open(filename)
    out = open(filename + '.out.txt','w')
    n = int(f.readline())
    for i in xrange(n):
        a,b = map(int,f.readline().split())
        low,high = int(math.ceil(math.sqrt(a))), int(math.floor(math.sqrt(b)))
        count = 0
        slow,shigh = str(low), str(high)
        hlow,hhigh = (len(slow)+1) / 2, (len(shigh)+1) / 2
        oddlow,oddhigh = len(slow) % 2, len(shigh) % 2
        xlow,xhigh = slow[:hlow], shigh[:hhigh]
        for x in find(xlow,xhigh,oddlow,oddhigh):
            if x**2 >= a and x**2 <= b and isp(str(x**2)):
                count += 1
        out.write('Case #'+str(i+1)+ ': '+ str(count)+'\n')
    out.close()
    f.close()

solve('D:\C-large-1.in')
