#!/usr/bin/env python3

import sys, os, re
import collections
import math
sys.setrecursionlimit(200)

def debug(x):
    print(x, file=sys.stderr) 


def gen_jamcoins(N, J):
    c = 1*(2**(N-1))+1
    ans = [] 
    for j in range(J):
        while(True):
            divisors = []
            c_str = "{0:b}".format(c) 
            debug("c_str = 0b%s" % c_str)
            for base in range(2, 11):
                is_prime = True
                d = int(c_str, base)
                #debug("  d = %d" % d)
                for divisor in range(3, min(int(math.sqrt(d)), 100000), 2):
                    if d % divisor == 0:
                        #debug("    %d %% %d = 0" % (d, divisor))
                        divisors.append(divisor)
                        is_prime = False
                        break
                if is_prime:
                    break

            if len(divisors) == 9:
                ans.append(c_str + " " + " ".join([str(x) for x in divisors]))
                break

            c += 2
        c += 2
    return "\n".join(ans)

        

def main():
    D = [x.strip() for x in sys.stdin.readlines()]
    T, D_raw = int(D[0]), D[1:]
    D = [x.split(" ") for x in D_raw]

    debug(T)
    debug(D)

    for numinput, d in enumerate(D, 1):
        N, J = int(d[0]), int(d[1])
        print("Case #%d:" % (numinput))
        print(gen_jamcoins(N, J))

if __name__ == '__main__':
    main()
