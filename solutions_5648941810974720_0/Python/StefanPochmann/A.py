foo = '''Z ZERO 0
W TWO 2
X SIX 6
U FOUR 4
R THREE 3
O ONE 1
F FIVE 5
V SEVEN 7
G EIGHT 8
I NINE 9'''.splitlines()

from collections import Counter

def naive(S):
    ctr = Counter(S)
    digits = []
    for line in foo:
        c, word, d = line.split()
        for _ in range(ctr[c]):
            digits.append(d)
            ctr -= Counter(word)
    return ''.join(sorted(digits))

for x in range(1, int(input()) + 1):
    S = input().strip()
    print('Case #%d:' % x, naive(S))
