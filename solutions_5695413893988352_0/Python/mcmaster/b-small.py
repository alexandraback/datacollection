"""
Problem B small

@author: Krisztian Balog
"""

def match(val, pattern):
    for i in range(len(val)):
        if pattern[i] != "?" and val[i] != pattern[i]:
            return False
    return True

def solve(a, b):
    n = len(a)
    aax = ""
    bbx = ""
    diff = 1000000

    for i in range(pow(10, n)):
        aa = str(i).zfill(n)
        if not match(aa, a):
            continue
        for j in range(pow(10, n)):
            bb = str(j).zfill(n)
            if not match(bb, b):
                continue
            d = abs(i-j)
            if d < diff:
                aax = aa
                bbx = bb
                diff = d

    return aax + " " + bbx


def run(infile, outfile):
    with open(infile, "r") as f:
        with open(outfile, "w") as fout:
            t = int(f.readline().strip())
            for i in range(t):
                input = f.readline().strip().split()
                sol = solve(input[0], input[1])
                print(sol)
                fout.write("Case #" + str(i + 1) + ": " + sol + "\n")

if __name__ == "__main__":
    run("B-small-attempt0.in", "B-small-attempt0.out")
