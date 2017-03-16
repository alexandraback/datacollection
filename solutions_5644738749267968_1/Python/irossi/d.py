'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
import os


if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)
    sys.argv.remove("--debug")

def main():
    problem_input = sys.stdin
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
        if os.path.isfile(input_file):
            problem_input = open(input_file)
        
    cases = int(problem_input.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case(problem_input)
        print "Case #%s: %s" % (case + 1, resp,)

def _deceitful(naomi, ken):
    k_idx = 0
    for block in naomi:
        if block > ken[k_idx]:
            k_idx += 1
    return k_idx
    
def _war(naomi, ken):
    score = 0
    k_idx = 1
    for block in reversed(naomi):
        if ken[-k_idx] > block:
            k_idx += 1
        else:
            score += 1
    return score       
    
def run_case(problem_input):
    _size = int(problem_input.readline())
    naomi = sorted([float(x) for x in problem_input.readline().split()])
    ken = sorted([float(x) for x in problem_input.readline().split()])
    logging.debug(naomi)
    logging.debug(ken)
    return "%s %s" % (_deceitful(naomi, ken), _war(naomi, ken))
    

if __name__ == "__main__":
    main()
