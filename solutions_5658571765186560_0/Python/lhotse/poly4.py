from __future__ import division
from itertools import combinations
from math import floor
from sys import argv

config_dict = {}

config_dict[(4,4)] = [1,0,1]
config_dict[(4,3)] = [1,1,1]
config_dict[(4,2)] = [0,0,1]
config_dict[(4,1)] = [0,0,1]
config_dict[(3,3)] = [0,1,0]
config_dict[(3,2)] = [0,1,1]
config_dict[(3,1)] = [0,0,0]
config_dict[(2,2)] = [0,0,1]
config_dict[(2,1)] = [0,0,1]
config_dict[(1,1)] = [0,0,0]

def solve(X, R, C):
    global config_dict
    yes = 'GABRIEL'
    no  = 'RICHARD'

    if X == 1: return yes
    if max(R,C) < X: return no
    # if min(R,C) < int(floor(X/2)): return no
    if config_dict[max(R,C), min(R,C)][4-X]: return yes

    return no 
    

def main():
    # filename = 'input.in'
    filename = 'dsmall.in'
    if len(argv) > 1:
        filename = argv[1]

    with open(filename) as f:
        T = int( f.readline() )
        case_count = 0
        for i in xrange(T):
            case_count += 1
            l = f.readline().rstrip('\n')
            X, R, C = map(int, l.split(' '))
            # print X, R, C,
            ans = solve(X, R, C)
            print "Case #" + str(case_count) + ": " + str(ans)
    
main()



