from collections import Counter

# fname = "B-small-attempt0.in.txt"
fname = "B-large.in.txt"
# fname = "test.in"

def solve(l, N):
  cnt = Counter()
  for row in l:
    for num in row:
      cnt[num] += 1
  missing = []
  for num in cnt.keys():
    if cnt[num] % 2 == 1:
      missing.append(num)

  return " ".join(map(str,sorted(missing)))

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      l = []
      N = int(f.readline())
      for j in xrange(2*N-1):
        l.append(map(int, f.readline().split()))
      print 'Case #%s: %s' % (i + 1, solve(l, N))

main()