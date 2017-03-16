from pprint import pprint
import sys

import numpy as np

def blah(K, N, P):
  # K characters already written, N in password,
  # P[i] = probability character i is right
  
  # compute probability first k characters are right for
  # k = 0...K
  P_all_right = np.zeros(K+1)
  for i in range(K+1):
    if i == 0:
      P_all_right[i] = 1.0
    else:
      P_all_right[i] = P_all_right[i-1]*P[i-1] 
  
  # enumerate strategies & calculate E[# of keys | strat, K, N]
  strat_scores = {}
  strat_scores['restart'] = 1 + N + 1.0
  for d in range(K+1):
    p_right = P_all_right[K-d]
    p_wrong = 1.0 - p_right
    n_right = (d + (N-(K-d)) + 1) 
    n_wrong = (d + (N-(K-d))+ 1 + N + 1)
    strat_scores['remove_{}'.format(d)] = \
      p_right*n_right + p_wrong*n_wrong
#  
#  pprint([K,N,P])
#  pprint(strat_scores)
#  
  
  min_key = argmin(strat_scores.items())
  return (min_key, strat_scores[min_key])


def argmin(kvs):
  return min( [(v,k) for (k,v) in kvs] )[1]

def load(path):
  result = []
  with open(path) as f:
    lines = list(f)[1:]
  for i in range(len(lines)):
    if lines[i].strip() == '':
      print 'lines {} is empty'.format(i)
    line = lines[i].strip().split(' ')
    if i % 2 == 0:
      (A,B) = int(line[0]), int(line[1])
    else:
      ps = [float(v) for v in line]
      result.append( (A,B,ps) )
  return result

#######
data = load(sys.argv[1])
with open(sys.argv[2], 'w') as f:
  for (i,d) in enumerate(data):
    res = blah(*d)
    res_str = "Case #{}: {}\n".format(i+1, res[1])
    print res_str
    f.write(res_str)