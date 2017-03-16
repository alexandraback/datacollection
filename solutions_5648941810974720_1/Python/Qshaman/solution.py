def applyable(d, s):
    for c in s:
        if not (c in d and d[c] > 0):
            return False
    return True

def sol(s):
    digits = ["ZERO", "TWO", "FOUR", "SIX", "EIGHT", "FIVE", "SEVEN", "THREE", "ONE", "NINE"]
    ans = [0, 2, 4, 6, 8, 5, 7, 3, 1, 9]
    letters = {}
    re = []
    for c in s:
        if c in letters:
            letters[c] += 1
        else:
            letters[c] = 1
    for i in range(len(digits)):
        while applyable(letters, digits[i]):
            re.append(ans[i])
            for c in digits[i]:
                letters[c] -= 1
    re = sorted(re)
    return ''.join(map(str, re))




T = int(raw_input())
for i in xrange(T):
    s = raw_input()
    print 'Case #%d: %s' % (i+1, sol(s))
