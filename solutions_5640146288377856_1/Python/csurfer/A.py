def process():
  R, C, W = map(int, raw_input().split())
  if C % W == 0:
    return R*(C/W) + W - 1
  else:
    return R*(C/W) + W

def main():
  tC = int(input())
  tc = tC
  while tc > 0:
    tc -= 1
    ans = process()
    print u"Case #{}: {}".format(tC-tc, ans)

if __name__ == "__main__":
  main()
