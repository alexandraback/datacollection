"""
Problem A

@author: Krisztian Balog
"""

DIGITS = [[0, "ZERO"], [2, "TWO"], [4, "FOUR"], [6, "SIX"], [8, "EIGHT"], [3, "THREE"], [7, "SEVEN"], [5, "FIVE"], [1, "ONE"], [9, "NINE"]]


def str_as_dict(input):
    """Creates a dict from a str with the character counts."""
    cnt = {}
    for i in range(len(input)):
        c = input[i]
        cnt[c] = cnt.get(c, 0) + 1
    return cnt


def solve(input):
    cnt = str_as_dict(input)

    number = []
    for d in DIGITS:
        dnum = d[0]
        dstr = d[1]

        dcnt = str_as_dict(dstr)
        found = True
        while found:
            n = 0
            for c, num in dcnt.items():
                if cnt.get(c, 0) >= num:
                    n += 1
            found = (n == len(dcnt))
            if found:
                #print("Found ", digit)
                #print(cnt)
                number.append(dnum)
                for c, num in dcnt.items():
                    cnt[c] -= num
                #print(cnt)

    if sum(cnt.values()) > 0:
        print("Error with input ", input)

    return "".join([str(n) for n in sorted(number)])


def run(infile, outfile):
    with open(infile, "r") as f:
        with open(outfile, "w") as fout:
            t = int(f.readline().strip())
            for i in range(t):
                input = f.readline().strip()
                sol = solve(input)
                print(sol)
                fout.write("Case #" + str(i + 1) + ": " + sol + "\n")

if __name__ == "__main__":
    run("A-small-attempt1.in", "A-small-attempt1.out")