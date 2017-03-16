import sys
import os

if len(sys.argv) < 2:
    sys.exit("Usage: %s [input]" % sys.argv[0])

if not os.path.exists(sys.argv[1]):
    sys.exit("Input file %s does not exist!" % sys.argv[1])

with open(sys.argv[1]) as f:
    lines = f.readlines()
    T = int(lines[0])
    inputs = map(lambda l : l.split(' '), lines[1:])

def solve(T, inputs):
    for t in xrange(T):
        # input variables
        [N] = map(lambda s : int(s), inputs[t])
        used = [False] * 10
        count = 0
        i = 0
        sleep = False
        while i < 1000:
            y = (i+1) * N
            for ch in str(y):
                digit = int(ch)
                if used[digit] == False:
                    used[digit] = True
                    count += 1 
                    if count == 10:
                        print "Case #%d: %d" % (t+1, y)
                        sleep = True
            i += 1
        
        if not sleep:
            print 'Case #%d: INSOMNIA' % (t+1)

#T = 5
#inputs = [0, 1, 2, 11, 1692]
solve(T, inputs)
