#!/usr/bin/env python
import sys, os.path, argparse
from copy import deepcopy

parser = argparse.ArgumentParser()
parser.add_argument( '-problem_id', default="A", )
parser.add_argument( '-problem_size', default="sample"  )
parser.add_argument( '--debug', default="0" )
args = parser.parse_args()

PROBLEM_ID = args.problem_id
PROBLEM_SIZE = args.problem_size

#PROBLEM_SIZE = "sample"

cnt = 0

def solve( smax, people_with_shyness_level ):
    '''
    standing ovation
    smax ... maximum level of shyness
    digits ... number of person with shyness level (starting with level 0)
    '''
    
    additional_people_to_fulfill_standing_ovation = 0
    people_standing = people_with_shyness_level[0]
    
    for i in range( 1, len(people_with_shyness_level) ):
        #print "i={}, standing={}, shynesslevel(i)={}" , i, people_standing, people_with_shyness_level[ i ]  
        if( i <= people_standing ):
            people_standing += people_with_shyness_level[i]
        else:
            additional_people_to_fulfill_standing_ovation += (i-people_standing)
            people_standing += people_with_shyness_level[i] + (i-people_standing)
            
  
    
    return additional_people_to_fulfill_standing_ovation




file_name = "{}-{}".format(PROBLEM_ID, PROBLEM_SIZE)
in_f = open('{}.in'.format(file_name), 'r')
out_f = open('{}.out'.format(file_name), 'w')

rl = in_f.readline
rl = sys.stdin.readline

testcases = rl()
n = 1
cnt = 0

while n <= int(testcases):
    smax, digits = rl().rstrip().split(" ")
    smax = int(smax)
    
    people_with_shyness_level = [ int(digits[i]) for i in range(0, len(digits))]
            
    answer = solve( smax, people_with_shyness_level )
    
    print "Case #" + str(n) + ": " + str(answer)
    out_f.write( "Case #" + str(n) + ": " + str(answer) + "\n" )
    
    n = n + 1


