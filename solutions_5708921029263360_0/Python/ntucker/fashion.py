import sys
import itertools
from collections import defaultdict

output_line = "Case #{X:d}: {answer}"


if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            J, P, S, K = list(map(int, inhandle.readline().strip().split()))


            abs = defaultdict(int)
            bcs = defaultdict(int)
            acs = defaultdict(int)
            solutions = []
            for j in range(J):
                for p in range(P):
                    for s in range(S):
                        ab = (j, p)
                        bc = (p, s)
                        ac = (j, s)
                        if abs[ab] >= K or bcs[bc] >= K or acs[ac] >= K:
                            continue
                        solutions.append(" ".join(map(str, [j + 1, p + 1, s + 1])))
                        abs[ab] += 1
                        bcs[bc] += 1
                        acs[ac] += 1

            outline = output_line.format(X=t + 1, answer=len(solutions))
            outline += "\n" + "\n".join(solutions)
            print(outline, file=outhandle)
            print(outline)

