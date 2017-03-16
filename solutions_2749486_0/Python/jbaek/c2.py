from math import *
from itertools import *
import os


def main():
    f = open("/home/jackie/Documents/Codejam/in")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        print "Case #%d:" % (i+1),
        correct = []
        x,y = split_to_int(lines)
        # positive, go west first
        if x > 0:
            correct.append('WE'*x)
        else:
            correct.append('EW'*abs(x))
        if y > 0:
            correct.append('SN'*y)
        else:
            correct.append('NS'*abs(y))
        print "".join(correct)




def recurse(x, y, wantx, wanty, jump, sofar, correct):
    print x, y, wantx, wanty
    vertical = True
    horizontal = True
    if correct:
        return
    if x == wantx and wanty == y:
        print sofar
        d = raw_input()
        correct.append(sofar)
        return
    if wantx != x and abs(wantx - x) < jump:
        print 'hi'
        return
    elif wanty != y and abs(wanty - y) < jump:
        print 'hi2'
        return
    if abs(wanty - y) < jump:
        vertical = False
    if abs(wantx - x) < jump:
        horizontal = False
    north = y+jump
    south = y -jump
    east = x+jump
    west = x-jump
    if vertical and abs(wanty - north) > jump:
        recurse(x, north, wantx, wanty, jump+1, sofar+"N", correct)
    if vertical and abs(wanty - south) > jump:
        recurse(x, south, wantx, wanty, jump+1, sofar+"S", correct)
    if horizontal and abs(wantx - east) > jump:
        recurse(east, y, wantx, wanty, jump+1, sofar+"E", correct)
    if horizontal and abs(wantx - west) > jump:
        recurse(west, y, wantx, wanty, jump+1, sofar+"W", correct)



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