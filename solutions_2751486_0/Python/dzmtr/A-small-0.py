consonants = [1] * 26
consonants[ord('a') - ord('a')] = consonants[ord('e') - ord('a')] = consonants[ord('i') - ord('a')] = consonants[ord('o') - ord('a')] = consonants[ord('u') - ord('a')] = 0
T = int(raw_input())
for t in xrange(1, T + 1):
    x = raw_input().split()
    s, n = x[0], int(x[1])
    m = len(s)
    ans = 0
    for k in xrange(n, m + 1):
        for i in xrange(0, m - k + 1):
            s2 = s[i:i + k]
            correct = False
            for j in xrange(i, i + k - n + 1):
                correct = all(consonants[ord(s[l]) - ord('a')] == 1 for l in xrange(j, j + n))
                if correct:
                    break
            if correct:
                ans += 1
    print "Case #{0}: {1}".format(t, ans)
