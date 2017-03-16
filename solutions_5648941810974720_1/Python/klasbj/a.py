import sys
from collections import Counter

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
uniq = ["Z", "O", "W", "T", "U", "F", "X", "S", "G", "I"]
order = [0, 2, 4, 6, 8, 1, 7, 5, 3, 9]

def solve(ws):
    c = Counter(ws)
    numbers = []
    # find numbers with unique letters in order
    for n in order:
        u = uniq[n]
        if u in c:
            m = c[u]
            numbers += [n]*m
            for ch in nums[n]:
                c[ch] -= m
    return ''.join(str(x) for x in sorted(numbers))

if __name__ == '__main__':
    lines = (x.strip() for x in sys.stdin.readlines()[1:])
    for t, l in enumerate(lines):
        print('Case #{}: {}'.format(t+1, solve(l)))

