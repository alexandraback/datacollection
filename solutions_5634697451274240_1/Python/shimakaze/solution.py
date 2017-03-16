def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for i in range(num_tests):
    pancakes = f.readline().strip()
    current = ''
    flips = -1
    print "Doing case %d" % (i+1)
    for j in range(len(pancakes)):
      if pancakes[j] != current:
        current = pancakes[j]
        flips += 1
        print "Just flipped to %s, flips %d" % (current, flips)
    if current == '-':
      flips += 1
    o.write("Case #%d: %d\n" % (i+1, flips))

solve('B-large.in')
