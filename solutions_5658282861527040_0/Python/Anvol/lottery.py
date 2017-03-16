def main():
    inp = open("input.txt", "r")
    out = open("output.txt", "w")
    test_count = int(splited_line(inp)[0])
    for x in xrange(1, test_count + 1):
        (A, B, K) = [int(i) for i in splited_line(inp)]
        a = solve(A, B, K)
        ans = "Case #%s: %s\n"
        print ans % (x, a)
        out.write(ans % (x, a))


def solve(A, B, K):
    r = 0
    for x in xrange(0, A):
        for y in xrange(0, B):
            if x & y < K:
                r += 1
    return r


def splited_line(f):
    return f.readline().strip('\r\n').split(' ')

if __name__ == '__main__':
    main()
