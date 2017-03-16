import sys

def solve(inpf):
  tokens = map(int, inpf.readline().strip().split())
  A = tokens[0]
  B = tokens[1]

  probs = map(float, inpf.readline().strip().split())

  curr_best = B + 2 # Give up and enter and retype and enter
  num_backspace = 0
  while True:
    to_try = B - A + 2 * num_backspace + 1 # backspace and then type all
    
    # Get probability of all correct
    prob = 1
    for i in xrange(A - num_backspace):
      prob = prob * probs[i]
 
    # If all correct, we need this much   
    at_least = prob * to_try
    if at_least >= curr_best:
      break

    # Expected trial for this strategy
    curr = at_least + (1 - prob) * (to_try + B + 1)
    if curr < curr_best:
      curr_best = curr
    num_backspace += 1

    # If even all correct is worse, just give up
    if to_try > curr_best:
      break

  return curr_best

if len(sys.argv) < 2: 
  print 'Usage: python *.py [input_file]'
  exit(-1)

inpf = open(sys.argv[1], 'r')

N = int(inpf.readline().strip())

for i in xrange(N):
  ans = solve(inpf)
  print 'Case #' + str(i+1) + ': ' + str(ans)
inpf.close()
