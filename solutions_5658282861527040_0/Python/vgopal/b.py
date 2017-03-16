f = open('b_small.txt')
T = int(f.readline())

for turn in range(1, T+1):
  A, B, K = [int(x) for x in f.readline().strip().split()]
  # print A, B, K
  num = 0
  for a in range(A):
    for b in range(B):
      if a & b < K:
        num += 1
  print "Case #" + str(turn) + ":", num
