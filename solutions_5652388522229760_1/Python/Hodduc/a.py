def solve(n):
    seen = set()
    cur = n

    if n == 0:
        return "INSOMNIA"

    while True:
        seen = seen | set(str(cur))
        if len(seen) == 10:
            return cur
        cur += n


def main():
    T = input()
    for t in range(1, T+1):
        N = input()
        print "Case #%d:" % t, solve(N)

#    for i in range(1, 1000000):
#        print i, solve(i)


main()

