#!/usr/bin/env python
import math
import sys

def get_actual(guess, r, t):
    guess = int(guess)
    while (2*r+2*guess-1)*guess > t:
        guess -= 1
    while (2*r+2*(guess+1)-1)*(guess+1) <= t:
        guess += 1
    return guess

def main():
    fname, gname = sys.argv[1:]
    with open(fname) as f, open(gname, 'w') as g:
        T = int(f.readline().strip())
        for i in xrange(T):
            r, t = map(int, f.readline().strip().split())
            
            guess = (1-2*r+math.sqrt((2*r-1)**2+8*t))/4
            print guess

            result = get_actual(guess, r, t)
            g.write("Case #{0}: {1}\n".format(i+1, result))

if __name__ == "__main__":
    status = main()
    sys.exit(status)
