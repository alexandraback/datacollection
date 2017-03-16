import random
import sys


t = int(raw_input())

def divisor(n):
    for i in range(2, int(n**.5) + 1):
        if n % i == 0:
            return i
    return 1

def next_num(length):
    num = '1'
    for i in range(1, length - 1):
        num += str(random.randint(0, 1))
    num += '1'
    return num

for it in range(1, t + 1):
    (N, J) = map(int, raw_input().split(' '))
    print "Case #{}:".format(it)
    history = set()
    correct = 0
    while correct < J:
        num = next_num(N)
        if num in history:
            continue
        divs = []
        for i in range(2, 11):
            divs.append(divisor( int(num, i) ))
        if 1 not in divs:
            correct += 1
            sys.stderr.write(str(correct) + '\n')
            print "{} {}".format(num, ' '.join(map(str, divs)))
        history.add(num)

