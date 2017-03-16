#!/usr/bin/env python
# coding: utf-8

import os
import sys

import numpy as np
import scipy as sp
import pylab as pl

def perr(errmsg):
  sys.stderr.write(errmsg);

def help(prog):
  perr("Usage: %s input\n" % prog);

def check_pattern(pattern):
  minval = pattern.min();
  if minval > 100:
    return True;

  [N, M] = pattern.shape;
  index  = pattern.flatten().tolist().index(minval);
  row = int(np.floor(index / M));
  col = index % M;
  #print minval, row, col;

  v = pattern.copy(); v[:, col][v[:, col]==minval] = minval + 100;
  #print "v", (v[:, col] > 100).min()
  #print np.hstack((pattern, v));
  if (v[:, col] > 100).min():
    if check_pattern(v):
      return True;

  h = pattern.copy(); h[row, :][h[row, :]==minval] = minval + 100;
  #print "h", (h[:, col] > 100).min();
  #print np.hstack((pattern, h));
  if (h[row, :] > 100).min():
    if check_pattern(h):
      return True;

  return False;

def main(argv):
  try:
    inpath  = argv[1];
  except:
    help(argv[0]);
    sys.exit(1);

  with open(inpath) as infile:
    T = int(infile.readline());
    for i in range(T):
      [N, M] = [int(x) for x in infile.readline().split()];
      pattern = np.zeros((N, M), np.int);
      for j in range(N):
        pattern[j, :] = [int(x) for x in infile.readline().split()];
      if (check_pattern(pattern)):
        print "Case #%d: YES" % (i+1);
      else:
        print "Case #%d: NO" % (i+1);
  

if __name__ == '__main__':
  main(sys.argv);
