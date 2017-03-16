#!/usr/bin/python

from sys import stdin as I

def solve(n):
  J, P, S, K = map(int, I.readline()[:-1].split(' '))

  JP = {}
  JS = {}
  PS = {}

  days = []

  for j in range(J):
    for p in range(P):
      for s in range(S):
        jp = str(j) + ':' + str((p+1) % P)
        js = str(j) + ':' + str((s+2) % S)
        ps = str((p+1) % P) + ':' + str((s+2) % S)
        if not jp in JP:
          JP[jp] = 0
        if not js in JS:
          JS[js] = 0
        if not ps in PS:
          PS[ps] = 0

        if JP[jp] < K and JS[js] < K and PS[ps] < K:
          days.append(str(j+1) + ' ' + str(((p+1) % P)+1) + ' ' + str(((s+2) % S)+1))
          JP[jp] += 1
          JS[js] += 1
          PS[ps] += 1

  print("Case #%i: %i" % (n+1, len(days)))
  for day in days:
    print day

T = int(I.readline())
for i in range(T):
    solve(i)