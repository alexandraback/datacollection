#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

class SaftyInNumber(object):
    EPS = 1E-9
 
    def __init__(self):
        pass 

    def satisfy(self, s, i, v):
        X = sum(s)
        p = s[i] + v*X
        fund = 1 - v
        for j in xrange(len(s)):
            if j != i and s[j] < p:
                fund -= float(p - s[j])/X     
        return fund <= 0

    def subsol(self, s, i):
        left, right = 0., 1.
        while right - left > self.EPS:
            mid = (left + right)/2
            if self.satisfy(s, i, mid):
                right = mid
            else:
                left = mid
        return right

    def sol(self, N, s):
        result = []
        for i in xrange(len(s)):
            result.append(self.subsol(s, i))
        return result


def test_cases(input):
    fi = open(input, "r")
    T = int(fi.next())
    for i in xrange(1, T + 1):
        row = [int(x) for x in fi.next().split(" ")]
        N = row[0]
        s = row[1:]
        yield i, N, s
    fi.close()

def main(input, output):
    fo = open(output, "w")
    problem = SaftyInNumber()
    for i, N, s in test_cases(input):
        result = problem.sol(N, s)
        print N, s
        fo.write("Case #{0}:".format(i)) 
        for r in result:
            fo.write(" %.6f" % (r*100))
        fo.write("\n")
    fo.close()
        
if __name__ == "__main__":
    # Parse command options
    from optparse import OptionParser
    parser = OptionParser(usage="Usage: %prog [options] param1 param2")    
    parser.add_option("-i", "--input", dest="input", help="Input file")
    parser.add_option("-o", "--output", dest="output", help="Output file")
    options, args = parser.parse_args()
    main(options.input, options.output)
