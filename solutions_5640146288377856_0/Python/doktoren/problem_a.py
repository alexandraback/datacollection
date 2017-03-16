'''
cat test.txt | python problem_a.py
'''

from sys import stdin

def main():
    tt = int(stdin.readline().strip())
    for t in xrange(1, tt+1):
        (r, c, w) = (int(s) for s in stdin.readline().strip().split(' '))
        a = (r-1)*(c/w)
        b = (c/w-1)
        c = (w if c % w == 0 else (w+1))
        # print "{} {} {}".format(a, b, c)
        result = a + b + c
        print "Case #{}: {}".format(t, result)

main()
