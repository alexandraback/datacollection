#!/usr/bin/env python
# encoding: utf-8

import sys
import os

def expectedKS(right_odd, pos, typed, pass_len):
  backspaces = typed - pos  
  expected_right = backspaces+(pass_len - pos)+1
  expected_wrong = expected_right + pass_len+1
  return (right_odd*expected_right) + (1.0-right_odd)*expected_wrong


def main():
	testcases = int(sys.stdin.readline().strip())
	for testcase in range(testcases):
	  typed, total_len = sys.stdin.readline().strip().split()
	  typed = int(typed)
	  total_len = int(total_len)
	  
	  odds = sys.stdin.readline().strip().split()
	  odds = [float(odd) for odd in odds]
	  
	  alright_prob = []
	  mult_result = 1.0
	  give_up_KS = total_len+2
	  best_ks = give_up_KS
	  
	  for odd, i in zip(odds, range(1, len(odds)+1)):
	    mult_result *= odd
	    expected_ks = expectedKS(mult_result, i, typed, total_len)
	    if expected_ks < best_ks:
	      best_ks = expected_ks
	      
	  sys.stdout.write("Case #%d: %.6f\n" % (testcase + 1, best_ks))
	    
	    
	  


if __name__ == '__main__':
	main()

