# https://code.google.com/codejam/contest/1460488/dashboard#s=p2
import sys

def readline():
    return sys.stdin.readline().rstrip()

def digits(num):
    d = 0
    n = num
    while True:
        d += 1
        n /= 10
        if n == 0:
            return d

t = int(readline())
for x in range(t):
    line = readline()
    (a, b) = [int(k) for k in line.split()]
    count = 0
    for i in range(a, b):
        done = False
        num1 = i
        num2 = 0
        shift1 = 10**(digits(i)-1)
        shift2 = 1
        seen = set()
        while not done:
            num2 += (num1 % 10) * shift2
            num1 /= 10
            if num1 == 0:
                break
            num = num2 * shift1 + num1
            if num > i and num != i and num >= a and num <= b and num not in seen:
                count += 1
                seen.add(num)
                #print 'i={} num1={} num2={} num={} shift1={} shift2={}'.format(i, num1, num2, num, shift1, shift2)
            shift1 /= 10
            shift2 *= 10
    print 'Case #{}: {}'.format(x+1, count)

