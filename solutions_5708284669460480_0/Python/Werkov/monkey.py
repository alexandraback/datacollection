import sys
from collections import Counter
from itertools import product

def price(word, target):
    t = len(target)
    w = len(word)
    return len([1 for i in range(w - t + 1) if word[i:i+t] == target])

def post(word, p):
    res = 1
    for c in word:
        res *= p[c]
    return res

def mmax(target, S):
    poses = list(i for i in range(len(target)) if target[:i] == target[-i:])
    overlay = max(poses) if len(poses) > 0 else 0

    rest = len(target) - overlay
    res = 1
    res += (S - len(target)) // rest
    return res

def solve(keyboard, target, S):
    p = Counter()
    for c in keyboard:
        p[c] += 1
    for c in p.keys():
        p[c] = p[c] / len(keyboard)

    ukeyboard = ({c: 1 for c in keyboard}).keys()
    possible = True
    for c in target:
        if c not in ukeyboard:
            possible = False
            break

    exp = 0
    for word in product(ukeyboard, repeat=S):
        word = ''.join(word)
        exp += price(word, target) * post(word, p)

    m = mmax(target, S) if possible else 0
    return m - exp


T = int(sys.stdin.readline().strip())
for t in range(T):
        K, L, S = [int(x) for x in sys.stdin.readline().strip().split()]
        keyboard = sys.stdin.readline().strip()
        target = sys.stdin.readline().strip()
        res = solve(keyboard, target, S)
        print("Case #{}: {}".format(t+1, res))
