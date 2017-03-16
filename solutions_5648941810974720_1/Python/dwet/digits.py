from collections import defaultdict

d = {
    0: "ZERO",
    1: "ONE",
    2: "TWO",
    3: "THREE",
    4: "FOUR",
    5: "FIVE",
    6: "SIX",
    7: "SEVEN",
    8: "EIGHT",
    9: "NINE",
}

def subtract_num(counts, num, times):
    for x in xrange(times):
        for c in d[num]:
            assert c in counts and counts[c]
            counts[c] -= 1

def subtract_easy(counts):
    ans = defaultdict(int)
    for (c, n) in [("Z", 0), ("X", 6), ("G", 8), ("W", 2), ("U", 4)]:
        if c in counts:
            ans[n] += counts[c]
            subtract_num(counts, n, counts[c])

    return ans

t = int(raw_input())
for case in range(1, t + 1):
    word = raw_input().strip()
    counts = defaultdict(int)
    for c in word:
        counts[c] += 1
    ans = subtract_easy(counts)

    def do_second(c, n):
        if counts[c]:
            ans[n] += counts[c]
            subtract_num(counts, n, counts[c])

    do_second("F", 5)
    do_second("V", 7)
    do_second("H", 3)
    do_second("O", 1)
    do_second("I", 9)

    a = ""
    for x in range(10):
        if x in ans:
            for y in xrange(ans[x]):
                a += str(x)

    print "Case #%s: %s" % (case, a)
