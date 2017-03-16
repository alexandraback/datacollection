#! /usr/bin/env python
import sys

if len(sys.argv) < 2:
  print "Please give me an input file."
  sys.exit(1)

input_file = open(sys.argv[1], 'r')
test_count = int(input_file.readline())

if len(sys.argv) < 3:
  output = sys.stdout
  print "Not given output file, writing to stdout."
else:
  output = open(sys.argv[2], 'w')
  print "Writing to '%s'" % sys.argv[2]

for test_case in range(1, test_count + 1):
  line = input_file.readline().strip().split(' ')
  B = int(line[0])
  M = int(line[1])
  possible = True
  slides = set()
  not_include = set()
  current_path = [1, 2, B]
  if M > (2 ** (B - 2)):
    # Cannot fit this many paths.
    possible = False
  else:
    difference =  (2 ** (B - 2)) - M
    val = 0
    while difference > 0:
      if (difference % 2) == 1:
        not_include.add((val + 1, B))
      val += 1
      difference /= 2
    M -= 1
    while M > 0:
      for i, j in [current_path[k:k+2] for k in range(0, len(current_path) - 1, 1)]:
        slides.add((i, j))
      M -= 1
      offset = 0
      if current_path[-2] == (B - 1):
        current_path = range(1, len(current_path) + 1)
        current_path.append(B)
      else:
        current_path[-2 - offset] += 1
#      while current_path[-2 - offset] == (B - 1 - offset):
#        offset += 1
#        if offset == (len(current_path) - 2):
#          break
#      if offset == (len(current_path) - 2):
#        current_path = range(1, len(current_path) + 1)
#        current_path.append(B)
#      else:
#        current_path[-2 - offset] += 1
#        offset -= 1
#        while offset >= 0:
#          current_path[-2 - offset] = current_path[-3 - offset] + 1
#          offset -= 1


  output.write('Case #%d: ' % test_case)
  if possible:
    output.write("POSSIBLE\n")
    for i in range(1, B + 1):
      for j in range(1, B + 1):
        if  j > i and (i, j) not in not_include:
          output.write('1')
        else:
          output.write('0')
      output.write('\n')
  else:
    output.write("IMPOSSIBLE")
    output.write('\n')
