from math import *
from itertools import *
import os


def main():
    f = open("/home/jackie/Documents/Codejam/in")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        print "Case #%d:" % (i+1),
        first = split_to_int(lines)
        armin = first[0]
        num_others = first[1]


        mins = [num_others]
        others = split_to_int(lines)
        others.sort()
        newothers = []

        if armin == 1:
            print num_others
            continue

        for i in range(len(others)):
            o = others[i]
            if o < armin:
                armin += o
            else:
                newothers = others[i:]
                break
        do_problem(armin, newothers, 0,mins)
        print min(mins)
        



def do_problem(armin, others,sofar, mins):
    if not others:
        mins.append(sofar)
        return
    curr = others[0]
    if curr < armin:
        armin += curr
        do_problem(armin, others[1:],sofar, mins)
    else:
        # remove
        mins.append(sofar+len(others))
        
        do_problem(armin+armin-1, others,sofar+1, mins)



# general helper functions

def split_to_int(lines):
    return [int(v) for v in lines.pop(0).split()]

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def isPrime(n):
  if n == 2 or n == 3: return True
  if n < 2 or n%2 == 0: return False
  if n < 9: return True
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return False
    if n%(f+2) == 0: return False
    f +=6
  return True    

main()