import sys

def solve_problem(line):
  tokens = line.split(' ')
  num_googlers = int(tokens[0])
  num_surp = int(tokens[1])
  best_res = int(tokens[2])

  answer = 0

  scores = map(int, tokens[3:])
  for score in scores:
    avg = score / 3
    if avg >= best_res:
      answer += 1
      continue
   
    # Has remainders 
    if score != avg * 3:
      if avg + 1 >= best_res:
        answer += 1
        continue
    
    # No more suprising score
    if num_surp == 0: continue

    leftover = score - best_res
    if leftover < 0: continue

    # Can do surprising score
    if best_res - leftover / 2 <= 2:
      num_surp -= 1
      answer += 1
    
  return answer

if len(sys.argv) < 2:
  print 'Usage: python problem2.py input'
  exit(-1)

rif = open(sys.argv[1], 'r')
num = int(rif.readline())

for i in xrange(num):
  problem = rif.readline().strip()
  answer = solve_problem(problem)
  print 'Case #' + str(i + 1) + ': ' + str(answer)
rif.close()
