import sys

def isfair(n):
    s = str(n)
    return s == s[::-1]

numbers = []

for i in range(1, int(1E7) + 1):
    if isfair(i) and isfair(i*i):
        numbers.append(i*i)

N = int(sys.stdin.readline())
for no in range(1, N+1):
    ans = 0
    a, b = sys.stdin.readline().split()
    a = int(a)
    b = int(b)
    for n in numbers:
        if a <= n <= b:
            ans += 1
    print "Case #{0}: {1}".format(no, ans)
