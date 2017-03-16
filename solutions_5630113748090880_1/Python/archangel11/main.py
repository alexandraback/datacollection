filename = "a.in"
outfilename = "output.txt"

from collections import defaultdict

def solve(f):
    output = 0
    n = int(f.readline())
    fmap = defaultdict(lambda: 0)
    for i in range(2*n-1):
        arr = map(int, f.readline().split())
        for a in arr:
            fmap[a] += 1
    missings = []
    for k, v in fmap.iteritems():
        if v % 2 == 1:
            missings.append(k)

    return " ".join(map(str, sorted(missings)))

def out(s, o):
    print s
    o.write("{}\n".format(s))

def main():
    f = open(filename)
    o = open(outfilename, 'w+')
    T = int(f.readline())
    t = 1
    while t <= T:
        output = solve(f)
        out("Case #{}: {}".format(t, output), o)
        t+=1

if __name__ == "__main__":
    main()
