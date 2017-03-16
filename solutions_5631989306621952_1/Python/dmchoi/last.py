

T = int(raw_input())

for t in range(T):

  S = raw_input().strip()

  last = ""
  for i in S:
    if (last == "" or last[0] <= i):
      last = i + last
    else:
      last = last + i

  print "Case #{}: {}".format(t+1, last)
