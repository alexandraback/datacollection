from math import *
from itertools import *
import os


def main():
    f = open("/home/jackie/Documents/Codejam/in")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        print "Case #%d:" % (i+1),
        maxday = 0
        numtribes = int(lines.pop(0))
        attacks = {}
        for j in range(numtribes):
            d, n, w, e, s, delta_d, delta_p, delta_s = split_to_int(lines)
            length = abs(e-w)
            for i in range(n):
                attack = {}
                attack["w"] = w
                attack["e"] = w+length
                attack["s"] = s

                if d not in attacks:
                    attacks[d] = []
                attacks[d].append(attack)
                if d > maxday:
                    maxday = d
                d += delta_d
                w += delta_p
                s += delta_s
        wall = {}
        count = 0
        # loop through days
        for i in range(maxday+1):
            if i in attacks:
                #  loop through attacks
                for attack in attacks[i]:
                    curr = attack["w"]
                    strength = attack["s"]
                    while curr < attack["e"]:
                        if curr not in wall:
                            wall[curr] = 0
                        if wall[curr] < strength:
                            count += 1
                            break
                        curr += 1
                # fix the walls
                for attack in attacks[i]:
                    curr = attack["w"]
                    strength = attack["s"]
                    while curr < attack["e"]:                        
                        if curr not in wall:
                            wall[curr] = 0
                        if wall[curr] < strength:
                            wall[curr] = strength
                        curr += 1
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