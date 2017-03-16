import string
import fractions
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))

def do_calc(i):
    params = string.split(string.strip(testcase.readline()), '/')
    p = int(params[0])
    q = int(params[1])
    gcd = fractions.gcd(p, q)
    p = p/gcd
    q = q/gcd
    log = math.log(q, 2)
    if log - math.floor(log) > 0.000000001 or log > 40.000000001:
        print "Case #"+str(i)+": impossible"
        return
    else:
        ancestors = p*(2**40/q)
        recent = 40
        for x in xrange(40, 0, -1):
            if ancestors%(2**x) == 1:
                print "Case #"+str(i)+": "+str(x)
                return
            else:
                ancestors = ancestors/2
        print "Case #"+str(i)+": impossible"

for i in xrange(1, num_cases+1):
    do_calc(i)
