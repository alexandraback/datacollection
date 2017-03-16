#!/usr/bin/python3
# -*- coding: utf-8 -*-

def main():
    in_file = open("A-large.in", mode='r')
    out_file = open("A-large.out", mode='w')

    T = int(in_file.readline())
    
    for t in range(T):
        tokens = in_file.readline().split('/')
        P, Q = [int(x) for x in tokens]
        MAX_N = 40

        result = 0
        for n in range(1, MAX_N+1):
            numerator = P * (2**n) - Q
            denominator = Q * (2**n)

            if numerator < 0:
                continue

            if numerator == 0:
                result = n
                break

            g = gcd(numerator, denominator)
            numerator /= g
            denominator /= g
            if (g>1 and denominator < (2**40) and (2**40) % denominator == 0):
                result = n
                break

        if result:
            out_file.write("Case #" + str(t+1) + ": " + str(result) + "\n")
        else:
            out_file.write("Case #" + str(t+1) + ": impossible\n")

    in_file.close()
    out_file.close()

def gcd(x, y):
   while y:
       x, y = y, x % y
   return x

def lcm(x, y):
   lcm = (x*y)//gcd(x,y)
   return lcm
    
if __name__ == '__main__':
    main()