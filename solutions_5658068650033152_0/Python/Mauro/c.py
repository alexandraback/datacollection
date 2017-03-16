import itertools

def read_ints():
  return map(int, raw_input().split())

def read_strs():
  return raw_input().split()

def remove_consecutive_duplicates(s):
  ret = s[0]
  for i in s[1:]:
    if i != ret[-1]:
      ret += i
  return ret

def solve(n, m, k):
  arr = [i for i in range((n+1) * (m+1)+20)]
  if k <= 4:
    return k
  if n > m:
    m,n = n,m
  
  for i in range(1,n-1):
    for j in range(i,m-1):
      used = (i+j)*2
      arr[used] = i*j + used
      if i==n-1:
	arr[used] -= j
      if i==n-2:
	arr[used] -= 2*j
      if j==m-1:
	arr[used] -= i
      if j==m-2:
	arr[used] -= 2*i
    
  ans = 123456789
  for used,enclosed in enumerate(arr):
    if enclosed >= k:
      ans = min(ans, used)

  return ans
  
for test in range(1, int(raw_input()) + 1):
  n,m,k = read_ints()
  sol = solve(n,m,k)
  print "Case #%d:" % (test,), sol