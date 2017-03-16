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

def solve(strs):
  ans = 0
  strs = map(remove_consecutive_duplicates, strs)
  for perm in itertools.permutations(strs):
    s = ''.join(perm)
    s = remove_consecutive_duplicates(s)
    if len(s) == len(set(s)):
      ans += 1
  return ans
  
for test in range(1, int(raw_input()) + 1):
  N, = read_ints()
  strs = read_strs()
  sol = solve(strs)
  print "Case #%d:" % (test,), sol