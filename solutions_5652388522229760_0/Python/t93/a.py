def main():
    t = int(raw_input())
    for i in xrange(t):
        n = int(raw_input())
        if n == 0:
            ans = "INSOMNIA"
        else:
            ans = solve(n)
        print "Case #%d: %s" % (i + 1, ans)

def solve(n):
    digits = set([])
    i = 0
    while len(digits) < 10:
        i += 1
        digits.update(set(str(n * i)))
    return n*i

if __name__ == "__main__":
    main()
