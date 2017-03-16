"""
Problem C

@author: Krisztian Balog
"""

def solve(input):
    w1c = {}
    w2c = {}
    for x in input:
        w1, w2 = x[0], x[1]
        if w1 not in w1c:
            w1c[w1] = []
        if w2 not in w2c:
            w2c[w2] = []
        w1c[w1].append(w2)
        w2c[w2].append(w1)

    f = 0
    removable = True
    while removable:
        removable = False
        # find removable edge
        for w1, w1out in w1c.items():
            if removable:
                break
            if len(w1out) > 1:
                for w2 in w1out:
                    if len(w2c[w2]) > 1:
                        removable = True
                        w1c[w1].remove(w2)
                        w2c[w2].remove(w1)
                        f += 1
                        #print(w1 + " => " + w2)
                        break

    return f

def run(infile, outfile):
    with open(infile, "r") as f:
        with open(outfile, "w") as fout:
            t = int(f.readline().strip())
            for i in range(t):
                n = int(f.readline().strip())
                input = []
                for j in range(n):
                    input.append(f.readline().strip().split())
                sol = solve(input)
                print(sol)
                fout.write("Case #" + str(i + 1) + ": " + str(sol) + "\n")
                #exit()

if __name__ == "__main__":
    #run("C-sample.in", "C-sample.out")
    run("C-small-attempt1.in", "C-small-attempt1.out")
