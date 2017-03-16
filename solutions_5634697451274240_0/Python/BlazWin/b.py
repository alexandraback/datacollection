ts = int(input())
for t in range(0, ts):
    s = input()
    mod = True
    ans = 0
    for c in reversed(s):
        if c == '-' and mod:
            ans += 1
            mod = False
        elif c == '+' and not mod:
            ans += 1
            mod = True
    print("Case #{}: {}".format(t + 1, ans))