from math import *
from itertools import *
import os


def main():
    f = open("/home/jackie/Documents/Codejam/in")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        print "Case #%d:" % (i+1),
        line = lines.pop(0).split()
        name = list(line[0])
        n = int(line[1])
        indexes = []
        count = 0
        length = len(name)
        i = 0
        for char in name:
            if char in vowels:
                count = 0
            else:
                count += 1
            if count >= n:
                indexes.append(i)
            i+=1
        #print indexes, length
        # now index has all the indexes
        count = 0
        i = 0
        for char in name:
            if not indexes:
                break
            curr = indexes[0]
            if i+n-1 > curr:
                indexes.pop(0)
            if not indexes:
                break
            curr = indexes[0]
            count += length - curr
            i += 1
        print count






def do_problem(pairsleft, left, right):
    pass


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