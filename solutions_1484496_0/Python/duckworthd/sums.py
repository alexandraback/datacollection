import re
import itertools
import sys
import os

import numpy as np
import ipdb

def process(values):
  values = np.array(values)
  N = len(values)
  for size1 in range(1,N):
    for size2 in range(size1):
      for (subset1, subset2) in itertools.product(k_subsets(values, size1), k_subsets(values,size2)):
        subset1 = subset1[0]
        subset2 = subset2[0]
        if subset1 != subset2 and sum(subset1) == sum(subset2):
          return (subset1, subset2)
        
def k_subsets_i(n, k):
    if k == 0 or n < k:
      yield set()
    elif n == k:
      yield set(range(n))
    else:
      for s in k_subsets_i(n - 1, k - 1):
        s.add(n - 1)
        yield s
      for s in k_subsets_i(n - 1, k):
        yield s

def k_subsets(s, k):
    s = list(s)
    n = len(s)
    for k_set in k_subsets_i(n, k):
      k_set = sorted(list(k_set))
      yield [[s[i] for i in k_set]]

def parse(lines):
  values = parseints(lines)
  return (values[1:],)

def parseints(line):
  return [int(v) for v in line.strip().split(" ")]

def main(path_in, path_out):
  with open(path_in) as f_in:
    with open(path_out, 'w') as f_out:
      n_examples = int(f_in.readline())
      for case in range(1, n_examples+1):
        
        # 1 line per case
        args = parse(f_in.readline())
        
        # actual code logic
        output = process(*args)
      
        if output is not None:
          out_str = "Case #{}:\n".format(case)
          out_str += " ".join([str(v) for v in output[0]]) + '\n'
          out_str += " ".join([str(v) for v in output[1]]) + '\n'
        else:
          out_str = 'Case #{}: Impossible\n'.format(case)
        print out_str
        f_out.write(out_str)

if __name__ == '__main__':
  sys.setrecursionlimit(100000000)
  main(sys.argv[1], sys.argv[2])