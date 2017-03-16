import sys

def solve(a, b):
    res = set()
    for i in range(a, b):
        s = str(i)
        l = len(s)
        for j in range(1, l):
            vs = s[j: l] + s[0: j]
            v = int(vs)
            if a <= v and i < v and v <= b and vs != s and (not (i, v) in res):
                #print i, v
                res.add((i, v))
    return len(res)

if __name__ == '__main__':
    fout = open("%s.out" % (sys.argv[0]), "w")
    num = int(sys.stdin.readline())
    for i in range(num):
        #print i
        a, b = map(int, str(sys.stdin.readline()).strip().split(' '))
        res = solve(a, b)
        fout.write("Case #%d: %s\n" % (i + 1, res))
    fout.close()