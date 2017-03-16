import sys
import os

def solve(T, inputs):
    for t in xrange(T):
        # input variables
        [S] = map(lambda s: s.strip(), inputs[t])
        s_out = S[0]
        # print s_out
        for i in xrange(1, len(S)):
            if ord(S[i]) >= ord(s_out[0]):
                s_out = S[i] + s_out
            else:
                s_out += S[i]

        print("Case #%d: %s" % (t+1, s_out))


def main():
    if len(sys.argv) < 2:
        sys.exit("Usage: %s [input]" % sys.argv[0])

    if not os.path.exists(sys.argv[1]):
        sys.exit("Input file %s does not exist!" % sys.argv[1])

    with open(sys.argv[1]) as f:
        lines = f.readlines()
        T = int(lines[0])
        inputs = map(lambda l : l.split(' '), lines[1:])

    solve(T, inputs)

if __name__ == "__main__":
    main()
