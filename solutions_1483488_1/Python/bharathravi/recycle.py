#!/usr/bin/python

def findForInt(integer, A, B):
  n = int(integer)
  length = len(integer)
  count = 0
  seen = []
  for i in range(1, length):
    m = int(integer[i:] + integer[0:i])
    if A <= n and n < m and m <= B:
      if m in seen:
        continue
      seen.append(m)
      count += 1

  return count


def find(A, B):
  count = 0
  for i in range(A, B):
    count += findForInt(str(i), A, B)
  return count

find(1111, 2222)

f = open('input2-large')
num = int(f.readline())

for i in range(0, num):
  output = 'Case #' + str(i+1) + ': '
  line = f.readline()
  words = line.split(None)
  A = int(words[0])
  B = int(words[1])
  output += str(find(A, B))
  print output
