import sys
import os

def solve(T, inputs):
    for t in xrange(T):
        # input variables
        [S] = inputs[t]
        S += '+'
        count = 0
        last_ch = S[0]
        for i in xrange(1, len(S)):
            ch = S[i]
            if ch != last_ch:
                count += 1
                last_ch = ch

        print "Case #%d: %d" % (t+1, count)

def main():
    if len(sys.argv) < 2:
        sys.exit("Usage: %s [input]" % sys.argv[0])

    if not os.path.exists(sys.argv[1]):
        sys.exit("Input file %s does not exist!" % sys.argv[1])

    with open(sys.argv[1]) as f:
        lines = f.readlines()
        T = int(lines[0])
        inputs = map(lambda l : l.strip().split(' '), lines[1:])

    solve(T, inputs)

if __name__ == "__main__":
    main()
