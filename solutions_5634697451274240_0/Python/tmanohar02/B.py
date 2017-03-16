def helper(s):
  ans = 0
  s = s + '+'
  for i in range(len(s)-1):
    if s[i] != s[i+1]:
      ans += 1
  return ans

def main():
  n = int(raw_input())
  for i in range(n):
    print "Case #{}: {}".format(i+1, helper(raw_input()))

if __name__ == '__main__':
  main()
