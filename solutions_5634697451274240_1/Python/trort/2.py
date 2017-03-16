def solver(s):
    count = 1
    if len(s) > 1:
        for i in range(len(s)-1, 0, -1):
            if s[i] != s[i-1]: count += 1
    if s[-1] == '+': count -= 1
    return count

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  # n = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
  s = raw_input().strip()
  ans = solver(s)
  print "Case #{}: {}".format(i, ans)