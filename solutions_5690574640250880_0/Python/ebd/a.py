#!/usr/bin/env python3.3


def main():
  def _print_grid(r1, r2, r3, c1, c2, c3):
    def _get_pos(r, c):
      if r == r1-1 and c == c1-1:
        return 'c'
      if r < r1-r2 or c < c1-c2:
        return '*'
      if r == r1-r2:
        return '*' if c < c1-c2+c3 else '.'
      if c == c1-c2:
        return '*' if r < r1-r2+r3 else '.'
      return '.'
    for row in range(r1):
      print(''.join(_get_pos(row, col) for col in range(c1)))

  def _solve(R, C, M):
    def _max_boundary_bombs(r, c):
      if min(r,c) <= 2:
        return 0
      return r-2+c-2-1

    free = R*C-M
    if free == 1:
      _print_grid(R, 1, 0, C, 1, 0)
      return
    if R == 1:
      _print_grid(R, 1, 0, C, free, 0)
      return
    if C == 1:
      _print_grid(R, free, 0, C, 1, 0)
      return
    for r in range(2,R+1):
      for c in range(2,C+1):
        bombs = r*c-free
        if 0 <= bombs <= _max_boundary_bombs(r, c):
          cc = min(bombs, c-2)
          rr = min(bombs-cc, r-2)
          _print_grid(R, r, rr, C, c, cc)
          return
    print('Impossible')

  tests = int(input())
  for case in range(tests):
    print('Case #{}:'.format(case+1))
    R, C, M = [int(x) for x in input().split()]
    _solve(R, C, M)
    

if __name__ == '__main__':
  main()
