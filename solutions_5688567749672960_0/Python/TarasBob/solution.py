FILE = 'sample.in'
#FILE = 'A-small-attempt0.in'
FILE = 'A-small-attempt1.in'

CACHE = {0:0}

def reverse(N):
  rev = int(str(N)[::-1])
  return rev


'''
def build_cache():
  for i in range(1, 1000001):
    prev_num = i-1
    rev_num = reverse(i)
    if rev_num:
      CACHE[i] = CACHE[min(prev_num, rev_num)] + 1
    else:
      CACHE[i] = CACHE[prev_num] + 1
'''

def bfs():
  start = 0
  queue = [(0, 0)]
  for i in range(1000001):
    N, dist = queue.pop(0)
    n1 = N + 1
    n2 = reverse(N)
    if n1 not in CACHE:
      CACHE[n1] = dist + 1
      queue.append((n1, dist + 1))
    if n2 not in CACHE:
      CACHE[n2] = dist + 1
      queue.append((n2, dist + 1))

bfs()



def solve(N):
  return CACHE[N]


with open(FILE, 'r') as f:

  for case_num in range(int(f.readline())):
    N = int(f.readline())
    print 'Case #{0}: {1}'.format(case_num + 1, solve(N))
