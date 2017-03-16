import sys

sys.stdin = open("A-small-attempt0.in", "r")
sys.stdout = open("A-small-attempt0.out", "w")

tn = int(input())
for test in range(tn):
    a, s = input().split()
    b = []
    for x in range(int(a) + 1):
        for y in range(ord(s[x]) - ord('0')):
            b.append(x)
    ans = 0
    for i, x in enumerate(b):
        ans = max(ans, x - i)
    print("Case #%d: %d" % (test + 1, ans))
