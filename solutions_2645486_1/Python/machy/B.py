import sys

def get_line():
    return sys.stdin.readline().strip()

def read_nums():
    return [int(item) for item in get_line().split(" ")]

def solve(E, R, values):
    ordered = []
    for i in range(len(values)):
        ordered.append( (i, values[i]) )
    ordered.sort(key=lambda x: (-x[1], x[0]))
    use_list = [0] * len(values)
    ans = 0
    for (i, v) in ordered:
        eng = E
        res = 0
        for j in xrange(0, i):
            eng -= use_list[j]
            eng = min(E, eng+R)
        for j in xrange(len(values)-1, i, -1):
            res += use_list[j]
            res = max(0, res-R)

        use = max(0, eng - res)
        ans += use * values[i]
        use_list[i] = use
    return ans


(T,) = read_nums()
for te in xrange(1, T+1):
    (E, R, N) = read_nums()
    values = read_nums()
    print "Case #%d: %d" % (te, solve(E, R, values))

