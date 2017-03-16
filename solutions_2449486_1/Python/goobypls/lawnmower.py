from sys import stdin

def lawn_test(lawn):
  """Takes a 2D list of integer values"""
  rowmax = [max(row) for row in lawn]
  colmax = [max([row[i] for row in lawn]) for i in range(len(lawn[0]))]

  for i in range(len(lawn)):
    for j in range(len(lawn[0])):
      if rowmax[i] > lawn[i][j] and colmax[j] > lawn[i][j]:
        return "NO"

  return "YES"

num = int(stdin.readline().strip())
out = []
for i in range(num):
  n, m = map(int, stdin.readline().strip().split())
  lawn = [[int(n) for n in stdin.readline().strip().split()] for i in range(n)]
  out.append(lawn_test(lawn))

for i, result in enumerate(out):
  print("Case #{}: {}".format(i+1, result))
