
s = open("A-small-attempt2.in").read().split("\n")
out = open("out.txt", "w")
T = int(s[0])
for t in range(T):
  A, N = map(int, s[2*t+1].split())
  arr = sorted(map(int, s[2*t+2].split()))
  i = 0
  j = 0
  k = 0
  r = range(N-1, -1, -1)
  if A == 1:
    k = N
  else:
    while i < N:
      if A <= arr[i]:
        j += 1
        A += A-1
      else:
        k += j
        j = 0
        A += arr[i]
        r[i] += k
        i += 1
    r.append(N)
    k = min(r)
  out.write("Case #"+str(t+1)+": "+str(k)+"\n")