def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    S = f.readline().strip()
    print "Doing case %d with S: %s\n" % (nt+1, S)
    bestWord = S[0]
    for i in range(1, len(S)):
      char = S[i]
      if char >= bestWord[0]:
        bestWord = char + bestWord
      else:
        bestWord = bestWord + char
    o.write("Case #%d: %s\n" % ((nt+1), bestWord))

solve('A-small-attempt0.in')
