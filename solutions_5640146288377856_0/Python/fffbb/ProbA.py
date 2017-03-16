import sys

def revnum(n) :
  strn = str(n)
  temp = ''
  for i in range(len(strn)) :
    temp += strn[-(i + 1)]
  return int(temp)

f = open(sys.argv[1], 'r')

T = int(f.readline())
for t in range(1, T + 1):
  print('Case #{0}:'.format(t), end = ' ')
  testcase = f.readline().split()
  R, C, W = int(testcase[0]), int(testcase[1]), int(testcase[2])

  if C == W:
    print(C)
  elif W == 1:
    print(C)
  else:
    count = 0
    while C > W:
      C -= W
      count += 1
    count += W
    print(count)
