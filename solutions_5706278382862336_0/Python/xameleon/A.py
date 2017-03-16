import sys
import math

def main():
    #infile = open('in')
    infile = open('A-small-attempt7.in')
    #infile = open('A-large.in')
    #infile = open('A-small-practice.in')
    #infile = open('A-large-practice.in')
    outfile = open('out', 'w')
    T = long(infile.readline())
    for i in xrange(T):
        outfile.write('Case #'+str(i+1)+': ' + solve(infile) + '\n')

def gcd (a, b):
    if a < b:
        return gcd(b, a)
    else:
        if b == 0:
            return a
        else:
            return gcd(b, a % b)

def solve(infile):
    p, q = map(long, infile.readline().split('/'))
    g = gcd(p, q)
    p /= g
    q /= g
    p0,q0 = p,q
    n = 0
    while q > 1:
        if q % 2 == 0:
            n += 1
            q /= 2
        else:
            n = -1
            break
    r = n
    if n != -1 and p > 1:
        r = n
        n2 = 0
        while 2**n2 <= p:
            n2 += 1
        n2 -= 1
        if n2 < n:
            r = n - n2
    return str(r) if n != -1 else 'impossible'
    #return '{:0.7f}'.format(res)

if __name__=='__main__':
    main()
