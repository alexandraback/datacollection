# coding: utf-8

import string, sys
from collections import Counter

def available(spelling, st):
    return all([st[ch] >= spelling[ch] for ch in spelling.keys()])

def solve(s):
    letters_cnt = Counter()
    for ch in s:
        letters_cnt[ch] += 1

    letters = {c: Counter() for c in xrange(10)}
    spelling = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    for d in xrange(10):
        for ch in spelling[d]:
            letters[d][ch] += 1

    """
    unique = []
    for d in xrange(10):
        cc = {x: 0 for x in letters[d].keys()}
        for dd in xrange(10):
            if d == dd:
                continue
            for l in letters[dd].keys():
                if l in cc:
                    cc[l] += 1
        for k in cc.keys():
            if cc[k] == 0:
                print "{} is unique".format(d)
                break
    """

    ans = []
    for digit in range(0, 10, 2) + range(1, 10, 2):
        while available(letters[digit], letters_cnt):
            for ch in letters[digit].keys():
                letters_cnt[ch] -= letters[digit][ch]
            ans += str(digit)

    if not all([x == 0 for x in letters_cnt.values()]):
        sys.stderr.write("{}\n".format(s))
        raise

    ans.sort()
    return ''.join(ans)

def main():
    n = int(raw_input())
    for i in xrange(n):
        s = raw_input().strip()
        ans = solve(s)
        print "Case #{}: {}".format(i+1, ans)

if __name__ == '__main__':
    main()
