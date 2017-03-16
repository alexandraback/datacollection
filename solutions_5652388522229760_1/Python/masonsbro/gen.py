def digits(x):
    d = set()
    while x > 0:
        d.add(x % 10)
        x /= 10
    return d

def calc(x):
    seen = set()
    cur = 0
    while len(seen) < 10:
        cur += x
        seen |= digits(cur)
    return cur

answers = []

print 0, "INSOMNIA"

for i in range(1, 1000001):
    answers.append(calc(i))
    print i, answers[-1]
