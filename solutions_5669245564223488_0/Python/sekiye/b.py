import itertools

def compress(s):
    s2 = []
    i = 0
    while i < len(s):
        while i + 1 < len(s) and s[i] == s[i + 1]:
            i += 1
        s2.append(s[i])
        i += 1
    return ''.join(s2)

def solve():
    N = int(raw_input())
    cars = map(compress, raw_input().split())
    cars.sort()
    count = 0
    for x in itertools.permutations(cars):
        s = ''.join(x)
        s2 = ''
        i = 0
        while i < len(s):
            while i + 1 < len(s) and s[i] == s[i + 1]:
                i += 1
            s2 += s[i]
            i += 1
        if len(s2) == len(set(s2)):
            count += 1
    return count % 1000000007

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
