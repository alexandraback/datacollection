'''
cat test_c.txt | python problem_c.py
'''

from sys import stdin
import itertools

def add_coin(current, d, c):
    result = current
    for n in xrange(1, c + 1):
        result |= (current << (d*n))
    return result

def p(current, v):
    pass
    #print "".join(str(n % 10) for n in xrange(v+1))
    #print "".join("x" if (current >> n) & 1 else " " for n in xrange(v+1))

def solve():
    (c, _d, v) = (int(s) for s in stdin.readline().strip().split(' '))
    denominations = set(int(s) for s in stdin.readline().strip().split(' '))
    target = (1L << (v+1)) - 1
    current = 1L
    for d in denominations:
        current = add_coin(current, d, c)
    p(current, v)
    if target == (current & target):
        return 0
    for solution in xrange(1, v):
        missing = (current & target) ^ target
        #print "Missing:"
        p(missing, v)
        candidates = tuple(n for n in xrange(1, missing.bit_length()/2 + 3) if n not in denominations)
        #print "{}".format(list(xrange(1, missing.bit_length()/2 + 1)))
        #print "Candidates: {} {}".format(candidates, solution)
        for adding in itertools.combinations(candidates, solution):
            #print "Trying to add {}".format(adding)
            tmp = current
            for d in adding:
                tmp = add_coin(tmp, d, c)
            if target == (tmp & target):
                return solution

def main():
    tt = int(stdin.readline().strip())
    for t in xrange(1, tt+1):
        print "Case #{}: {}".format(t, solve())

main()
