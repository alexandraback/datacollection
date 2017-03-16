import argparse

parser = argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def gold_lead(K,C,S):
  if K/C > S:
    return 'IMPOSSIBLE'
  else:
    ret = []
    unchecked_idx = 0
    while unchecked_idx < K:
      if unchecked_idx+C <= K:
        ret.append(compute_index([i for i in range(unchecked_idx, unchecked_idx+C)],K))
        unchecked_idx += C
      else:
        ret.append(compute_index([i for i in range(unchecked_idx, K)],K))
        unchecked_idx = K
    ret_str = [str(i+1) for i in ret]
    return ' '.join(ret_str)


def compute_index(li,b):
  ret = 0;
  for i in li:
    ret *= b
    ret += i
  return ret


with open(fin,'r') as input, open(fout,'w') as output:
  T = int(input.readline().rstrip('\n'))
  for i in range(0,T):
    s = input.readline().rstrip('\n')
    l = [int(i) for i in s.split(' ')]
    K = l[0]
    C = l[1]
    S = l[2]
    #print('Case #{}: {}\n'.format(i+1,last_num(n)))
    output.write('Case #{}: {}\n'.format(i+1,gold_lead(K,C,S)))