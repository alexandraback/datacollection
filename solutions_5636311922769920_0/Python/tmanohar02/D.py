def helper(k, c, s):
  if k == s:
    for i in range(k):
      print i+1,
  print


def main():
  n = int(raw_input())
  for i in range(n):
    k, c, s = [int(t) for t in raw_input().split(' ', 3)]
    print "Case #{}:".format(i+1),
    helper(k, c, s)

if __name__ == '__main__':
  main()

