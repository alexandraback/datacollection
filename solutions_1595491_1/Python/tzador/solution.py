#!/usr/bin/env python
test = 'large'
input = open('%s.in'%test)
output = open('%s.out'%test, 'w')

def is_possible(total, p):
  possible = False
  without_special = False
  for i in range(0, 11):
    for j in range(0, 11):
      for k in range(0, 11):
        if i + j + k != total:
          continue
        best = max(i, j, k)
        worst = min(i, j, k)
        diff = best - worst
        if diff > 2:
          continue
        if best < p:
          continue
        possible = True
        if diff <= 1:
         without_special = True
  needs_special = not without_special
  return (possible, needs_special)

def solve(S, p, totals):
  without_special_count = 0
  with_special_count = 0
  for total in totals:
    (possible, needs_special) = is_possible(total, p)

    if possible:
      if needs_special:
        with_special_count += 1
      else:
        without_special_count += 1

  return without_special_count + min(with_special_count, S)


T = int(input.readline())
for t in range(T):
  ints = map(int, input.readline().split())
  print >>output, "Case #%d:"%(t+1), solve(ints[1], ints[2], ints[3:])

