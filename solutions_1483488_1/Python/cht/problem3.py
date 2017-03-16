import sys

def solve_problem(line):
  tokens = line.split(' ')
  low = int(tokens[0])
  high = int(tokens[1])

  total = 0

  for n in xrange(low, high):
    ms = []
    l = len(str(n))
    for i in xrange(1, l):
      m = (n / (pow(10, i))) + (n % (pow(10, i))) * (pow(10, l - i)) 
      if m > n and m not in ms and m <= high:
        ms.append(m)
        total += 1
  return total

if len(sys.argv) < 2:
  print 'Usage: python problem3.py input'
  exit(-1)

rif = open(sys.argv[1])

num = int(rif.readline())

for i in xrange(num):
  ans = solve_problem(rif.readline().strip())
  print 'Case #' + str(i + 1) + ': ' + str(ans)

rif.close()
