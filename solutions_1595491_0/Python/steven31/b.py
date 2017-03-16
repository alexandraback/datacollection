import sys

def get_three(n, isSpecial = False):
    if n == 0:
        return 0, 0, 0
    if n == 1:
        return 1, 0, 0
    t = n % 3
    b = n / 3
    if isSpecial:
        if t == 0:
            return b + 1, b, b - 1
        elif t == 1:
            return b + 1, b + 1, b - 1
        elif t == 2:
            return b + 2, b, b
    else:
        if t == 0:
            return b, b, b
        elif t == 1:
            return b + 1, b, b
        elif t == 2:
            return b + 1, b + 1, b

# t: number of Googlers
# s: number of surprising triplets
# p: minimum number <- get number of triplets at least p
# n: total points of the Googlers
def solve(t, s, p, n):
    res = 0
    remain = s
    for i, an in enumerate(n):
        a, b, c = get_three(an, False)
        if p - a == 1 and remain and (a - c == 0 or (a == b)):
            a, b, c = get_three(an, True)
            remain -= 1
        if a >= p:
            res += 1
    return res

if __name__ == '__main__':
    fout = open("%s.out" % (sys.argv[0]), "w")
    num = int(sys.stdin.readline())
    for i in range(num):
        line = map(int, str(sys.stdin.readline()).strip().split(' '))
        #print line
        t, s, p, n = line[0], line[1], line[2], line[3:]
        res = solve(t, s, p, sorted(n, reverse=True))
        fout.write("Case #%d: %s\n" % (i + 1, res))
    fout.close()