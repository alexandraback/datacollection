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

def check(n):
    s = int(math.sqrt(float(n)))
    for i in range(2,s+1):
        if n%i == 0:
            return i
    return -1

def call(num):
    num = i2b(num)
    for i in range(2,11):
        n = anyBaseToDecimal(i,num)
        if check(n) == -1:
            return False
    return True

def printResult(num):
    num = i2b(num)
    num.reverse()
    ans = ''.join(num)
    num.reverse()
    for i in range(2,11):
        n = anyBaseToDecimal(i,num)
        ans += ' '
        ans += str(check(n))
    return ans

def Main():
    j = 50
    target = open('output.txt', 'w')
    target.truncate()
    target.write('Case #1:\n')
    for i in range(1<<(15),1<<(16)):
        if (i&1) == 0:
            continue;
        if call(i) == True:
            x = printResult(i)
            target.write("%s" % x )
            target.write('\n')            
            j-=1
            print(j)
            print(x)
        if j == 0:
            break
