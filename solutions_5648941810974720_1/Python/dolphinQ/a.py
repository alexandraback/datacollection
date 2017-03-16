import sys, math
def rs():
    return sys.stdin.readline().strip()
def ri():
    return int(sys.stdin.readline().strip())
def ras():
    return list(sys.stdin.readline().strip())
def rai():
    return map(int,sys.stdin.readline().strip().split())
def raf():
    return map(float,sys.stdin.readline().strip().split())

def solve():
    s = rs()
    hashmap = {}
    for x in s:
        hashmap[x] = hashmap.get(x,0) + 1

    words = [("ZERO", "Z", 0), 
            ("SIX", "X", 6),
            ("TWO", "W", 2),
            ("SEVEN", "S", 7),
            ("EIGHT", "G", 8),
            ("THREE", "H", 3),
            ("FOUR", "R", 4),
            ("ONE", "O", 1),
            ("FIVE", "F", 5),
            ("NINE", "E", 9),
            ]
    result = []
    for word, let, r in words:
        count = hashmap.get(let, 0)
        if count == 0: continue
        result = result + [r]*count
        for l in word:
            hashmap[l] -= count
    return "".join(map(str,sorted(result)))


T = ri()
result = []
for x in xrange(T):
    result.append("Case #%s: %s"%((x+1), solve()))
with open("./hard.out", "w+") as f:
    f.write("\n".join(result))