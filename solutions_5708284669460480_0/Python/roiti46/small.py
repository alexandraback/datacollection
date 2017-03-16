import itertools as it
T = int(raw_input())
for case in xrange(1, T + 1):
    K, L, S = map(int, raw_input().split())
    a = raw_input()
    b = raw_input()
    
    mx = ans = cnt = 0
    for word in it.product(a, repeat = S):
        word = "".join(word)
        tmp = 0
        for i in xrange(0, S - L + 1):
            if word[i:i+L] == b:
                ans += 1
                tmp += 1
        mx = max(mx, tmp)
        cnt += 1
    print "Case #%d: %.10f" % (case, mx - 1.0 * ans / cnt)
