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

def solve( D, Pi ):
    '''
   infinity house of pancakes
    D ... number of diners
    Pis ... array of pancakes at the
    
    consume each minute
    special minute: shift amount of cakes to another positions (position are available infinite)
    algo:
        shift to empty position if distance from maximum to second maximum is > 3
    '''
    minutes = 0
    Pi.sort()
    
    while( len(Pi) >= 1 and Pi[0] > 0 ):
        #print Pi
        if( len(Pi) >= 2 ):
            subtractor = Pi[-1]
        else:
            subtractor = 0
        if( Pi[-1] - subtractor > 3 ):
            # special minute
            # divide Pi 
            cakes_to_be_divided = Pi[-1]
            Pi[-1] = cakes_to_be_divided / 2
            Pi.append( cakes_to_be_divided - Pi[-1])
            Pi.sort()
        else:
            # normal consuming minute
            Pi = [Pi[i]-1 for i in range(0,len(Pi))]
        while( len(Pi) > 0 and Pi[0] == 0):
            del Pi[0]
        minutes += 1
        
    return minutes




file_name = "{}-{}".format(PROBLEM_ID, PROBLEM_SIZE)
in_f = open('{}.in'.format(file_name), 'r')
out_f = open('{}.out'.format(file_name), 'w')

rl = in_f.readline
rl = sys.stdin.readline

testcases = rl()
n = 1
cnt = 0

while n <= int(testcases):
    D = (int)(rl().rstrip())
    Pi = [ int(arg) for arg  in rl().split(" ") ]
            
    answer = solve( D, Pi )
    
    print "Case #" + str(n) + ": " + str(answer)
    out_f.write( "Case #" + str(n) + ": " + str(answer) + "\n" )
    
    n = n + 1


