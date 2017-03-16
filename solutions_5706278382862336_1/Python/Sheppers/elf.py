#!/usr/local/bin/python3
from fractions import gcd
import sys

def elf(P, Q):
   powers = [pow(2, i) for i in range(40)]
   if Q not in powers:
      return -1
   for i in range(40):
      full_elf = Q/pow(2, i)
      if(full_elf <= P):
            ancestors = pow(2, 40)*((pow(2, i)-1)/pow(2, i))
            elves_left = P - full_elf
            if(ancestors >= elves_left*pow(2, 40)/Q):
               return i
   return -1

def main():
    
    cases = int(input())
    
    for i in range(cases):
        s = input()
        P = int(s.split('/')[0])
        Q = int(s.split('/')[1])
        GCD = gcd(P, Q)
        P /= GCD
        Q /= GCD
        
        gen = elf(P, Q)
        if gen >= 0:
           print("Case #"+str(i + 1) + ": " + str(gen))
        else:
            print("Case #" + str(i + 1) + ": impossible")
        
                        
if __name__ == '__main__':
    main()


