#!/usr/bin/python
import sys
import numpy as np
import itertools

inputs = [line.strip() for line in sys.stdin]

T = int(inputs[0])

def find_num_of_ways(slides, B):
  C = slides
  n = C[0,B-1]
  while sum(sum(C)) > 0:
    C = np.dot(slides,C)
    n += C[0,B-1]
  return n

def bin_seq(N):
  return [np.array(seq) for seq in itertools.product("01", repeat=N)]

def create_matrix(arr, B):
  out = np.zeros((B,B))
  ind = np.triu_indices(B,1)
  out[ind] = arr
  return out

def all_possibilities(B, M):
  N = B * (B-1) / 2
  for seq in bin_seq(N):
    S = create_matrix(seq, B)
    if find_num_of_ways(S, B) == M:
      return S
  return -1

for t in xrange(T):
  B,M = [int(x) for x in inputs[t+1].split()]
  slides = all_possibilities(B,M)
  if type(slides) == int:
    print("Case #{0}: {1}".format(t+1, "IMPOSSIBLE"))
  else:
    print("Case #{0}: {1}".format(t+1, "POSSIBLE"))
    for r in xrange(slides.shape[0]):
      print "".join([str(int(x)) for x in slides[r]])
