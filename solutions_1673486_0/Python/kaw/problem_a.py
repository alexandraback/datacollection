import sys

f = open(sys.argv[1])

N = int(f.readline().split()[0])


for i in range(N):
  line = f.readline().split()
  A = int(line[0])
  B = int(line[1])
  line = f.readline().split()
  prob = []
  if A > 0:
    prob.append(float(line[0]))
    for j in range(A-1):
      prob.append(prob[j]*float(line[j+1]))
  expect = {}
  expect['kt'] = prob[A-1]*(B-A+1) + (1-prob[A-1])*(B-A+1+B+1) # keep trying
  expect['enter'] = B+2 # immediate enter
  for j in range(A):
    backspaces = j+1
    e_correct = prob[A-backspaces]*(B-A+backspaces+1)
    e_wrong = (1-prob[A-backspaces])*(B-A+backspaces+1+B+1)
    expect['bs%d' % backspaces] = e_correct + e_wrong
  print 'Case #%d: %.6f' % (i+1, min(expect.values()))


f.close()