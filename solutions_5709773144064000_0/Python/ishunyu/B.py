def output(f, n, s):
  f.write("Case #" + str(n) + ": " + s + "\n")

def calc(C, F, X, n):
  res = 0
  rate = 2.0

  for i in range(n):
    res = res + C / rate
    rate = rate + F

  res = res + X / rate

  return res

fin = open("B-small-attempt0.in", "r")
fout = open("B-small-attempt0.out", "w")

num = int(fin.readline())

for i in range(num):
  arr = fin.readline().split(" ")
  C = float(arr[0])
  F = float(arr[1])
  X = float(arr[2])

  prev = calc(C, F, X, 0)
  curr = 0
  

  for j in range(1, int(X)):
    curr = calc(C, F, X, j)
    if curr < prev:
      prev = curr
    else:
      break

  output(fout, i+1, str('{:.7f}'.format(round(prev, 7))))
