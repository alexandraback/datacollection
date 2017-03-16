#!/usr/bin/env python3.3


def main():
  def _get_sorted_input():
    return sorted([float(x) for x in input().split()])

  def _war(n, naomi, ken):
    k = 0
    for i in range(n):
      if naomi[-i-1] < ken[-k-1]:
        k += 1
    return n-k

  def _deceitful_war(n, naomi, ken):
    k = 0
    for i in range(n):
      if naomi[i] > ken[k]:
        k += 1
    return k

  tests = int(input())
  for case in range(tests):
    n = int(input())
    naomi, ken = _get_sorted_input(), _get_sorted_input()
    print('Case #{}: {} {}'.format(case+1, _deceitful_war(n, naomi, ken), _war(n, naomi, ken))) 


if __name__ == '__main__':
  main()
