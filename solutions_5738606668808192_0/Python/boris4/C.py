#!/usr/bin/python
import sys
import random
import time

N = int(sys.stdin.readline().strip())
J = int(sys.stdin.readline().strip())

numbers = {}

def divisor(x):
    curTime = time.time()
    i = 2
    while i * i <= x:
        if time.time() - curTime > 1:
            return -1
        if x % i == 0:
            return i
        i += 1
    return -1

while len(numbers) < J:
    curNum = 2**(N - 1) + random.randint(0, 2**(N-2) - 1) * 2 + 1
    sys.stderr.write('.')
    sys.stderr.flush()
    
    if curNum not in numbers:
        ok = True
        divisors = []
        for base in range(2, 11):
            num = 0
            cnt = 0
            tmpNum = curNum
            while tmpNum > 0:
                num = (tmpNum % 2) * base**cnt + num
                tmpNum /= 2
                cnt += 1

            div = divisor(num)
            if div == -1:
                ok = False
                break
            else:
                divisors.append(div)

        if ok:
            numbers[curNum] = divisors
            sys.stderr.write('\nFound number: %s - %s\n' % (curNum, len(numbers)))

print 'Case #1:'
for a, b in numbers.iteritems():
    num = 0
    cnt = 0
    while a > 0:
        num = (a % 2) * 10**cnt + num
        a /= 2
        cnt += 1
    sys.stdout.write('%s' % num)
    for x in b:
        sys.stdout.write(' %s' % x)
    sys.stdout.write('\n')
