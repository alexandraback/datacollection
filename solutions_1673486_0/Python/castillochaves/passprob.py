import sys

def main():
    with sys.stdin as f:
        for x in range(int(f.readline())):
            solve(f, x+1)

def solve(f, case):
    l = f.readline().split()
    A = float(l[0])
    B = float(l[1])
    p = [float(x) for x in f.readline().split()]
    best_case = B + 2
    Pacc = 1.0
    for pi in p:
        Pacc *= pi
    for i in range(int(A)):
        if i > 0:
            Pacc /= p[-i]
        ok = (B - A + 2*i + 1)
        exp = Pacc * ok + (1 - Pacc) * (ok + B + 1)
        if exp < best_case:
            best_case = exp
    print "Case #%d: %.6f" % (case, best_case)

if __name__ == '__main__':
    main()
