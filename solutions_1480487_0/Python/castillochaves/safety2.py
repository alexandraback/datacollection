import sys

def main():
    with sys.stdin as f:
        for x in range(int(f.readline())):
            solve(f, x+1)

def solve(f, case):
    inputs = f.readline().split()
    N = int(inputs[0])
    s = [int(x) for x in inputs[1:]]
    t = sum(s)
    j = [float(k) / t for k in s]
    x = []
    add = 0
    for i in range(N):
        x.append(100*(2-N*j[i])/N)
        if x[-1] < 0:
            add = -x[-1] if -x[-1] > add else add
    x = [k+add for k in x]
    print "Case #%d: %s" % (case, ' '.join([str(k) for k in x]))

if __name__ == '__main__':
    main()
