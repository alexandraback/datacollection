import sys

with open(sys.argv[1]) as f:
    total = int(f.readline().strip())
    for i in range(total):
        sys.stdout.write("Case #%d: " % int(i+1))
        C, F, X = [float(i) for i in f.readline().strip().split()]
        S = 0.0
        N = 0
        while C / (2 + F*N) + X / (2 + F*(N+1)) < X / (2 + F*N):
            S += C / (2 + F*N)
            N += 1
        S +=  X / (2 + F*N)
        print("%.7f" % S)
