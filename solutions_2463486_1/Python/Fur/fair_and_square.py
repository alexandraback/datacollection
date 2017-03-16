from bisect import bisect, bisect_left

fs = []

def gen():
    
    def check(s):
        s = str(int(s) ** 2)
        for i in xrange(len(s) + 1 >> 1):
            if s[i] != s[-i - 1]:
                return None
        fs.append(int(s))

    def rec(n, s = ''):
        if len(s) == n:
            if s: 
                check(s + s[::-1])
            for i in xrange(10):
                check(s + str(i) + s[::-1])
        else:
            for i in xrange(10):
                if not s and not i: continue
                rec(n, s + str(i))
    
    for i in xrange(4):
        rec(i)
    
    fs.sort()


def main(case):
    a, b = map(int, raw_input().strip().split())
    print 'Case #{}:'.format(case),
    print bisect(fs, b) - bisect_left(fs, a)

gen()
T = input()
for i in xrange(T):
    main(i + 1)
