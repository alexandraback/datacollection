#!/usr/bin/python

from sys import stdin as I

def solve(h):
  N = int(I.readline())

  left = {}
  right = {}

  neighbors = {}
  titles = []

  for n in range(N):
    L, R = I.readline()[:-1].split(' ')

    titles.append([L, R])

    if not L in left:
      left[L] = [0, False]

    if not L in neighbors:
      neighbors[L] = []

    if not R in right:
      right[R] = [0, False]

    left[L][0] +=1
    neighbors[L].append(R)
    right[R][0] +=1

  sol = 0
  second = []

  for title in titles:
    l = title[0]
    r = title[1]
    if left[l][0] == 1 or right[r][0] == 1:
      left[l][1] = True
      right[r][1] = True
    else:
      second.append(title)

  for title in second:
    l = title[0]
    r = title[1]
    if left[l][1] and right[r][1]:
      sol += 1
    else:
      left[l][1] = True
      for n in neighbors[l]:
        if not right[n][1]:
          right[n][1] = True
          break

  print("Case #%i: %i" % (h+1, sol))

T = int(I.readline())
for i in range(T):
    solve(i)