#!/usr/bin/env python3.3


def main():
  tests = int(input())
  for case in range(tests):
    C, F, X = [float(x) for x in input().split()]

    i = 0
    s0 = 0
    while True:
      s0 += C/(2+(i-1)*F) if i else 0
      s = s0 + X/(2+i*F)
      if not i or s < last:
        last = s
        i += 1
      else:
        break
    print('Case #{}: {:.7f}'.format(case+1, last))


if __name__ == '__main__':
  main()
