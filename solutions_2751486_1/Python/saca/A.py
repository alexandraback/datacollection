#!/usr/bin/env python3

from sys import stdin

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

vowels = set(['a', 'e', 'i', 'o', 'u'])

def brute(name, n):
  l = len(name)
  nv = 0
  for i in range(l):
    for j in range(i, l):
      crt_run = 0
      for k in name[i:j+1]:
        if not k in vowels:
          crt_run += 1
          if crt_run >= n:
            nv += 1
            break
        else:
          crt_run = 0

  return nv

def nvalue(name, n):
  run = [0] * len(name)
  crt_run = 0
  for i in range(len(name)):
    if not name[i] in vowels:
      crt_run += 1
    else:
      crt_run = 0
    run[i] = crt_run

  nv, l, last_run = 0, len(name), -1
  for i, r in enumerate(run):
    if r >= n:
      left = max(0, last_run - n + 2)
      nv += (2 + i - n - left) * (l - i)
      #print(name, i, r, left, last_run)
      #print(2+i-n-left, l-i)
      #print(nv)
      #print('------------')
      last_run = i

  return nv

if __name__ == "__main__":
  resp = Responder()
  solve = nvalue
  for _ in range(int(stdin.readline())):
    splits = stdin.readline().split()
    resp.write(solve(splits[0], int(splits[1])))
