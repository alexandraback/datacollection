with open("A-large.in") as fin:
    with open("A.out", "w") as fout:
        T = int(fin.readline())
        for q in range(T):
            vals = fin.readline().strip().split(" ")
            A = int(vals[0])
            B = int(vals[1])
            vals = fin.readline().strip().split(" ")
            p = [float(x) for x in vals]
            pCorrect = 1
            for k in p:
                pCorrect *= k
            best = 2 + B
            for i in range(len(p)):
                best = min(best, i + pCorrect * (B - A + 1) + (1 - pCorrect) * (2 * B - A + 2))
                pCorrect /= p[len(p) - i - 1]
                A -= 1
            fout.write("Case #" + str(q + 1) + ": %(best)06f" % {"best": best} + "\n")
