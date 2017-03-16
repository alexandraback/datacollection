#!/usr/bin/env python
import sys, os.path, argparse
from copy import deepcopy

parser = argparse.ArgumentParser()
parser.add_argument( '-problem_id', default="B", )
parser.add_argument( '-problem_size', default="sample"  )
parser.add_argument( '--debug', default="0" )
args = parser.parse_args()

PROBLEM_ID = args.problem_id
PROBLEM_SIZE = args.problem_size

cnt = 0

def solve( X, R, C ):
    '''
    Ominous Omino
    
    '''
    if X >= 7:
        isGabrial = False
    elif X > R and X > C:
        isGabrial = False
    elif R * C % X != 0:
        isGabrial = False
    elif (X + 1) // 2 > min(R, C):
        isGabrial = False
    elif X in (1, 2, 3):
        isGabrial = True
    elif X == 4:
        isGabrial = min(R, C) > 2
    elif X == 5:
        isGabrial = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        isGabrial = min(R, C) > 3
        
    return 'GABRIEL' if isGabrial else 'RICHARD'




file_name = "{}-{}".format(PROBLEM_ID, PROBLEM_SIZE)
in_f = open('{}.in'.format(file_name), 'r')
out_f = open('{}.out'.format(file_name), 'w')

rl = in_f.readline
rl = sys.stdin.readline

testcases = rl()
n = 1
cnt = 0

while n <= int(testcases):
    X, R, C = [ int(arg) for arg  in rl().split(" ") ]
    answer = solve( X, R, C )
    
    print "Case #" + str(n) + ": " + str(answer)
    out_f.write( "Case #" + str(n) + ": " + str(answer) + "\n" )
    
    n = n + 1


