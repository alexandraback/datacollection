import math
def i2b(a):
    s = []
    while a > 0:
        s.append(str((a&1)))
        a >>= 1
    return s;

def anyBaseToDecimal(base,num):
    l = len(num)
    p = 1
    ans = 0
    for i in range(l):
        if num[i] == '1':
           ans += p
        p *= base
    return ans

def check(n,b):
    s = max(10000,int(math.sqrt(n)))
    i = 2
    n = n + b**31
    while i <= s:
        if n%i == 0:
            #print(n,b,i)
            return i
        i += 1
    return -1

def call(num):
    num = i2b(num)
    for i in range(2,11):
        n = anyBaseToDecimal(i,num)
        if check(n,i) == -1:
            return False
    #print(num)
    return True

def printResult(num):
    num = i2b(num)
    num.reverse()
    ans = ''.join(num)
    ans = int(ans) + 10**31
    ans = str(ans)
    num.reverse()
    for i in range(2,11):
        n = anyBaseToDecimal(i,num)
        ans += ' '
        ans += str(check(n,i))
    return ans

def Main():
    j = 500
    target = open('output.txt', 'w')
    target.truncate()
    target.write('Case #1:\n')
    i = -1
    while j > 0:
        i += 2
        if call(i) == True:
            x = printResult(i)
            target.write("%s" % x )
            target.write('\n')            
            j-=1
            print(j)
            print(x)
