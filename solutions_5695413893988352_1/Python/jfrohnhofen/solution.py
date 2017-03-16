#!/usr/bin/python

from sys import stdin as I

def finish(A, B, which):
  if which:
    A = ''.join(A).replace('?', '0')
    B = ''.join(B).replace('?', '9')
  else:
    A = ''.join(A).replace('?', '9')
    B = ''.join(B).replace('?', '0')

  return (abs(int(A) - int(B)), A, B)

def solve(n):
  A, B = I.readline()[:-1].split(' ')

  A = [x for x in A]
  B = [x for x in B]
 
  smallest = 10**20
  As = str(10**20)
  Bs = str(10**20)

  for i in range(len(A)):
    if A[i] == '?' and B[i] == '?':
      A[i] = '0'
      B[i] = '0'
      
      A_ = A[::]
      B_ = B[::]
      A_[i] = '1'
      d, x, y = finish(A_, B_, True)
      if d == smallest:
        if int(x) == int(As):
          if int(y) < int(Bs):
            Bs = y
        if int(x) < int(As):
          As = x
          Bs = y
      if d < smallest:
        smallest = d
        As = x
        Bs = y

      A_ = A[::]
      B_ = B[::]
      B_[i] = '1'
      d, x, y = finish(A_, B_, False)
      if d == smallest:
        if int(x) == int(As):
          if int(y) < int(Bs):
            Bs = y
        if int(x) < int(As):
          As = x
          Bs = y
      if d < smallest:
        smallest = d
        As = x
        Bs = y


    elif A[i] == '?':
      A[i] = B[i]

      if int(A[i]) > 0:
        A_ = A[::]
        B_ = B[::]
        A_[i] = str(int(A[i]) - 1)
        d, x, y = finish(A_, B_, False)
        if d == smallest:
          if int(x) == int(As):
            if int(y) < int(Bs):
              Bs = y
          if int(x) < int(As):
            As = x
            Bs = y
        if d < smallest:
          smallest = d
          As = x
          Bs = y

      if int(A[i]) < 9:
        A_ = A[::]
        B_ = B[::]
        A_[i] = str(int(A[i]) + 1)
        d, x, y = finish(A_, B_, True)
        if d == smallest:
          if int(x) == int(As):
            if int(y) < int(Bs):
              Bs = y
          if int(x) < int(As):
            As = x
            Bs = y
        if d < smallest:
          smallest = d
          As = x
          Bs = y

    elif B[i] == '?':
      B[i] = A[i]

      if int(B[i]) > 0:
        A_ = A[::]
        B_ = B[::]
        B_[i] = str(int(B[i]) - 1)
        d, x, y = finish(A_, B_, True)
        if d == smallest:
          if int(x) == int(As):
            if int(y) < int(Bs):
              Bs = y
          if int(x) < int(As):
            As = x
            Bs = y
        if d < smallest:
          smallest = d
          As = x
          Bs = y

      if int(B[i]) < 9:
        A_ = A[::]
        B_ = B[::]
        B_[i] = str(int(B[i]) + 1)
        d, x, y = finish(A_, B_, False)
        if d == smallest:
          if int(x) == int(As):
            if int(y) < int(Bs):
              Bs = y
          if int(x) < int(As):
            As = x
            Bs = y
        if d < smallest:
          smallest = d
          As = x
          Bs = y

    elif A[i] != B[i]:
      d, x, y = finish(A, B, int(A[i]) > int(B[i]))
      if d == smallest:
        if int(x) == int(As):
          if int(y) < int(Bs):
            Bs = y
        if int(x) < int(As):
          As = x
          Bs = y
      if d < smallest:
        smallest = d
        As = x
        Bs = y

      break

  d, x, y = finish(A, B, True)
  if d == smallest:
    if int(x) == int(As):
      if int(y) < int(Bs):
        Bs = y
    if int(x) < int(As):
      As = x
      Bs = y
  if d < smallest:
    smallest = d
    As = x
    Bs = y

  print("Case #%i: %s %s" % (n+1, ''.join(As), ''.join(Bs)))

T = int(I.readline())
for i in range(T):
    solve(i)
