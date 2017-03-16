from sys import stderr
for t in range(1,input()+1):
  s,n = raw_input().split()
  n = int(n)
  ans = 0
  for i in range(len(s)+1):
    for j in range(len(s)+1):
      con = 0
      good = False
      for ch in s[i:j]:
        if ch in {'a','e','i','o','u'}: con = 0
        else:
          con += 1
          if con >= n: good = True
      if good: ans += 1
  print 'Case #%i:'%t, ans
