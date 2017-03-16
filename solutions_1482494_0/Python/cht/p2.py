import sys

def solve(inpf):
  level = int(inpf.readline().strip())

  levels = []
  achieves = []
  for i in xrange(level):
    levels.append(map(int, inpf.readline().strip().split()))
    achieves.append(0)

  num_star = 0
  num_attempts = 0
  while True:
    success = 1
    while success: # Always try to complete with 2-star first
      success = 0
      for i in xrange(level):
        if achieves[i] != 2 and levels[i][1] <= num_star:
          num_star += 2 - achieves[i]
          achieves[i] = 2
          success = 1
          num_attempts += 1
  
    if sum(achieves) == 2 * level:
      return str(num_attempts)
 
    success = 0
    curr_best = 0
    for i in xrange(level): # Try complete with 1-star now
      if achieves[i] == 0 and levels[i][0] <= num_star: 
        if curr_best < levels[i][1]:
          curr_best = levels[i][1]

    for i in xrange(level):
      if achieves[i] == 0 and levels[i][0] <= num_star and levels[i][1] == curr_best:
        success = 1
        achieves[i] = 1
        num_star += 1
        num_attempts += 1
        break
    if sum(achieves) == 2 * level:
      return str(num_attempts)
    if success == 0:
      return 'Too Bad'
  return ''

if len(sys.argv) < 2: 
  print 'Usage: python *.py [input_file]'
  exit(-1)

inpf = open(sys.argv[1], 'r')

N = int(inpf.readline().strip())

for i in xrange(N):
  ans = solve(inpf)
  print 'Case #' + str(i+1) + ': ' + ans
inpf.close()
