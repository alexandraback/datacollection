import sys

sys.stdout = open('output', mode='w')

def solve(v):
    s, r = 0, 0
    for i, c in enumerate(v):
        x = max(i - s, 0)
        r += x
        s += x + int(c)
    return r

output = 'Case #{}: {}'
t = int(input())
for i in range(t):
    m, s = input().split()
    print(output.format(i + 1, solve(s)))

sys.stdout.close()
