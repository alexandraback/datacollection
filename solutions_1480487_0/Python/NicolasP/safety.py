import sys
import math

def solve(scores):
    #print scores
    totalpoints = sum(scores)
    minpoints = totalpoints * 2 / float(len(scores))
    nover = sum(1 for x in scores if x > minpoints)
    if nover > 0:
        #minpoints = math.ceil(totalpoints / 2.0)
        minpoints = totalpoints / float(len(scores) - nover)

    #print 'nover', nover, 'minpoints', minpoints, totalpoints
    return [max(0.0, 100 * (minpoints - s) / float(totalpoints)) for s in scores]

def main():
    with open(sys.argv[1]) as f:
        f.readline()
        for i, line in enumerate(f):
            l = [int(x) for x in line.split()]
            res = solve(l[1:])
            print 'Case #%d: %s' % (i+1, ' '.join(str(x) for x in res))

if __name__ == "__main__":
    main()
