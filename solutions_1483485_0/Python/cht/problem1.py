import sys

if len(sys.argv) < 5:
  print 'Usage: python problem1.py [sample_input] [sample_output] [real_input] [real_output]'
  exit(-1)

sif = open(sys.argv[1], 'r')
sof = open(sys.argv[2], 'r')

mapping = dict()

num_tests = int(sif.readline())
for i in xrange(num_tests):
  line = sif.readline().strip()
  answer = sof.readline().strip()
  start_ind = answer.find(':')
  answer = answer[start_ind+2:]

  for c in xrange(len(line)):
    key = line[c]
    if key not in mapping:
      mapping[key] = answer[c]
 
sif.close()
sof.close()

rif = open(sys.argv[3], 'r')
rof = open(sys.argv[4], 'w')

num_tests = int(rif.readline())
for i in xrange(num_tests):
  line = rif.readline().strip()
  
  rof.write('Case #' + str(i + 1) + ': ')
  answer = ''
  for c in xrange(len(line)):
    answer += mapping[line[c]]

  rof.write(answer + '\n')

rif.close()
rof.close() 
