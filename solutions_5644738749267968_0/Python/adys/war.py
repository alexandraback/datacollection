import sys

def war(N,L1,L2):
  score = 0
  p = N-1
  beg, end = 0,N-1
  while p >= 0:
    if L1[p] > L2[end]:
      beg += 1
      score += 1
    else:
      end -= 1
    p -= 1
  return score

def dec_war(N,L1,L2):
  score = 0
  p,q = 0,0
  while p < N:
    if L1[p] > L2[q]:
      q += 1
      score += 1
    p += 1
  return score

if __name__ == '__main__':
  T = int(sys.stdin.readline().split()[0])
  for t in range(1,T+1):
    N = int(sys.stdin.readline().split()[0])
    Naomi = map(float,sys.stdin.readline().split())
    Naomi.sort()
    Ken = map(float,sys.stdin.readline().split())
    Ken.sort()
    print 'Case #{}: {} {}'.format(t,dec_war(N,Naomi,Ken),war(N,Naomi,Ken))
