t = int(input())

for curt in range(1, t + 1):
    s = input()
    s += "+"
    prev = '!'
    ans = 0
    for c in s:
        if c != prev:
            ans += 1
        prev = c
    print("Case #%d: %d" % (curt, ans - 1))

    