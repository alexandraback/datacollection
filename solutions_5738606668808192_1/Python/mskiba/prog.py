import random
import sys
import gc
import primefac

t = int(raw_input())

def divisor(n):
    d = primefac.primefac(n).next()
    if d == n:
        return 1
    return d

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
        #print 'check ' + num
        if num in history:
            continue
        divs = []
        for i in range(2, 11):
            d = divisor( int(num, i) )
            divs.append(d)
            if d == 1:
                break
        if 1 not in divs:
            correct += 1
            sys.stderr.write(str(correct) + '\n')
            print "{} {}".format(num, ' '.join(map(str, divs)))
            history.add(num)


