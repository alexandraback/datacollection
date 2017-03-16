from sys import stdin, stdout, stderr


def nums(fd, t):
    l = fd.readline()
    return [t(n) for n in l.split(" ")]

best = [10**6] * (10**6 + 10)
best[0] = 0
best[1] = 1


def flip(i):
    s = "".join(reversed(str(i)))
    return long(s)


for i in xrange(1, 10**6 + 2):
    best[i+1] = min(best[i+1], best[i] + 1)
    f = flip(i)
    best[f] = min(best[f], best[i] + 1)


def solve(N):
    return best[N]


if __name__ == "__main__":
    cases = int(stdin.readline())
    for c in range(1, cases + 1):
        N = int(stdin.readline().split()[0])
        ans = solve(N)
        stdout.write("Case #{0}: {1}\n".format(c, ans))
