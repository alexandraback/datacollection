from collections import defaultdict


"""z = 0 cut e r o
w = 2
u = 4
x = 6
g = 8
o = 1
t = 3
f = 5
s = 7
n = 9"""
for t in range(int(input().strip())):
    # l = list(map(int, input().strip().split()))
    s = input().strip()
    count = defaultdict(int)
    for c in s:
        count[c] += 1
    ans = ""
    for a in [('ZERO', '0'), ('WTO', '2'), ('UFOR','4'), ('XSI','6'), ('GEIHT','8'), ('ONE', '1'), ('THREE', '3'), ('FIVE', '5'), ('SEVEN', '7'), ('INNE', '9')]:
        num = count[a[0][0]]
        if num > 0:
            ans += a[1] * num
            for c in a[0]:
                count[c] -= num
    ans = ''.join(sorted(ans))

    print("Case #%d: %s" % (t + 1, ans))
