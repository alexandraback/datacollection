import sys

def maxEn(e, r, vals):
  opt = []
  e += 1
  for i in vals:
    opt.append([0]*e)
  #opt[val][e]
  #val is reversed
  for i in range(len(opt[0])):
    opt[0][i] = i * vals[-1]
  for act in range(1, len(opt)):
    val = vals[len(vals)-1-act]
    for remaining in range(len(opt[act])):
      poss = []
      for use in range(remaining+1):
        poss.append(use * val + opt[act-1][min(e-1, remaining-use+r)])
      opt[act][remaining] = max(poss)
  return opt[len(vals)-1][e-1]

if __name__ == "__main__":
  lines = sys.stdin.readlines()
  i = 1
  case = 1
  while i < len(lines):
    e, r, _ = [int(x) for x in lines[i].strip().split(' ')]
    vals = [int(x) for x in lines[i+1].strip().split(' ')]
    en = maxEn(e, r, vals)
    print "Case #{}: {}".format(case, en)
    i += 2
    case += 1
