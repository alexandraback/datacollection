from math import *
from itertools import *
import os
from decimal import *

ALLGRIDS = []

def main():
    global ALLGRIDS
    f = open("/home/jackie/Documents/Codejam/in")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        ALLGRIDS = []
        print "Case #%d:" % (i+1),
        guide = split_to_int(lines)
        number = guide[0]
        x = guide[1]
        y = guide[2]
        diamonds = []
        grid = {}

        if x == 0 and y == 0:
            print "1.0"
            continue

        ALLGRIDS.append(grid)

        do_problem(number, diamonds)

        total = len(ALLGRIDS)
        win = 0
        for grid in ALLGRIDS:
            if x in grid and grid[x] >= y+1:
                win += 1
        answer = str(Decimal(win)/Decimal(total))
        if "." not in answer:
            answer += ".0"
        print answer




def do_problem(number,diamonds):
    global ALLGRIDS
    for i in range(number):
        for j in range(len(ALLGRIDS)):
            helper(ALLGRIDS[j], 0)

# drops one diamond
def helper(grid, pos):
    global ALLGRIDS
    if pos not in grid:
        grid[pos]=0
    highest = grid[pos]

    if blockedleft(grid, pos):
        if blockedright(grid,pos):
            grid[pos]+=2
            return
        else:
            helper(grid, pos+1)
            return
    elif blockedright(grid,pos):
        helper(grid, pos-1)
        return
    # go on ground
    elif highest == 0:
        grid[pos]=1
        return
    else:
        # right
        newgrid = grid.copy()
        ALLGRIDS.append(newgrid)
        helper(newgrid, pos+1)
        # left
        helper(grid, pos-1)



def blockedleft(grid, pos):
    return pos-1 in grid and grid[pos-1]>grid[pos]
def blockedright(grid, pos):
    return pos+1 in grid and grid[pos+1]>grid[pos]

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

g = {0:1, 2:1}
#helper(g, 0)
#print ALLGRIDS
main()

