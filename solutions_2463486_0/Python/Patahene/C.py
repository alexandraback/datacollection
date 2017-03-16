#!/usr/bin/env python
import math
import itertools



def is_palindrome(trg):
    trg = str(trg)
    if trg == trg[::-1]:
        return True
    else:
        return False

def itr():
    small = [1, 4, 9]
    for s in small:
        yield s
    for i in xrange(1, 25):
        if i!=1:
            for pre in itertools.product('12', repeat=1):
                for post in itertools.product('012', repeat=i-1):
                    tmp = pre + post
                    tmp =  int(''.join(tmp + tmp[:len(tmp)-1][::-1]))
                    tmp = tmp**2
                    if is_palindrome(tmp):
                        #print str(tmp**2)+'\t'+str(tmp)
                        yield tmp
        for pre in itertools.product('12', repeat=1):
            for post in itertools.product('012', repeat=i-1):
                tmp = pre + post
                tmp =  int(''.join(tmp + tmp[:len(tmp)][::-1]))
                tmp = tmp**2
                if is_palindrome(tmp):
                    yield tmp


def read_testcase(f):
    A, B = map(int, f.readline().strip().split())
    return A, B

def solve(AB):
    A, B = AB
    count = 0
    gen = itr()
    for p in gen:
        if A <= p <= B:
            count += 1
        if p > B:
            break
    print count
    return str(count)

if __name__ == '__main__':
    ans = []
    with open('C-small-attempt0.in') as f:
        T = int(f.readline())
        print 'T =',T
        for i in xrange(T):
            ans.append(solve(read_testcase(f)))

    with open('ans.txt', 'w') as f:
        for i, a in enumerate(ans, start=1):
            #print a
            f.write('Case #%d: %s\n'%(i, a))






