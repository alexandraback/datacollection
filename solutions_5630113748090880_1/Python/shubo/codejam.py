import sys
import os

def solve(T, inputs):
    inp = 0
    for t in xrange(T):
        # input variables
        N = int(inputs[inp][0])
        rows = []
        for i in xrange(1, 2*N):
            rows.append(map(lambda s: int(s), inputs[inp+i]))
        inp += 2*N

        counts = {}
        for r in rows:
            for el in r:
                if el not in counts:
                    counts[el] = 0
                counts[el] += 1

        result = []
        for key in counts:
            if counts[key] % 2 == 1:
                result.append(key)

        print "Case #%d: %s" % (t+1, " ".join(map(lambda s: str(s), sorted(result))))


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
