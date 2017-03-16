def solver(n):
    if n == 0:
        return "INSOMNIA"
    else:
        unappeared = set([str(i) for i in range(10)])
        nn = 0
        while len(unappeared) > 0:
            nn += n
            for c in str(nn):
                if c in unappeared:
                    unappeared.remove(c)
        return nn

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
  ans = solver(n[0])
  print "Case #{}: {}".format(i, ans)