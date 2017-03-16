import sys

Done = False

Sums = {}

def parse(l):
    return [int(x) for x in l.split()[1:]]

def solve(s):
    global Done
    global Sums

    Done = False
    Sums = {}

    sum_rec(s, [])

    r = None
    m = float("Inf")
    for k, v in Sums.items():
        if len(v) == 2:
            if k < m:
                r = "\n".join(" ".join([str(y) for y in x]) for x in v)
                m = k

    if r != None:
        return r

    return "Impossible"

def sum_rec(s, partial):
    global Done
    global Sums

    if Done == True:
        return

    ssum = sum(partial)

    if ssum > 0:
        if ssum in Sums:
            Sums[ssum].append(partial)
            Done = True
        else:
            Sums[ssum] = [partial]

    for i in range(len(s)):
        sum_rec(s[i+1:], partial + [s[i]])

if __name__ == "__main__":
    f = open(sys.argv[1])

    N = int(f.readline())

    i = 1
    for j in range(N):
        s = parse(f.readline())

        print "Case #%d:\n%s" % (i, solve(s))

        i += 1
