from sys import stdin
from math import sqrt
from math import ceil

def palindrome(start, stop):
    if stop < 10:
        for i in xrange(int(ceil(sqrt(start))), int(sqrt(stop))+1):
            yield i*i
    else:
        for i in xrange(int(ceil(sqrt(start))), 10):
            yield i*i
    done = False
    i = 1
    while not done:
        L = str(i)
        done = True
        r = int(L + L[::-1])
        if r*r <= stop:
            done = False
            if r*r >= start:
                yield r*r
        for j in xrange(10):
            r = int(L + str(j) + L[::-1])
            if r*r <= stop:
                done = False
                if r*r >= start:
                    yield r*r
        i += 1

def is_palindrome(num):
    L = [int(i) for i in str(num)]
    if L[::-1] == L:
        return True
    else:
        return False

def main():
    for case in range(1, int(stdin.readline()) + 1):
        A,B = map(int, stdin.readline().split())
        count = 0
        for i in palindrome(A,B):
            if is_palindrome(i):
                count += 1
        print "Case #" + str(case) + ": " + str(count)

if __name__=="__main__":
    main()
