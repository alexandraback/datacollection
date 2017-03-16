t = int(input())
for cn in range(t):
    s = input()
    a = ""
    for c in s:
        a = c + a if c + a > a + c else a + c
    print("Case #%d: %s" % (cn + 1, a))
