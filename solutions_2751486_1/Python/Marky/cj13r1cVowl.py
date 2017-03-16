from sys import stderr
for t in range(1,input()+1):
  s,n = raw_input().split()
  n = int(n)
  c = 0
  for ch in s[:n-1]:
    if ch in 'aeiou': c = 0
    else: c += 1
  ans = bak = 0
  for j,ch in enumerate(s[n-1:]):
    if ch in 'aeiou': c = 0
    else: c += 1
    if c >= n:
      ans += (j+1-bak)*(len(s)-(j+n-1))
      bak = j+1
      #print>>stderr, ch,ans 
  print 'Case #%i:'%t, ans
