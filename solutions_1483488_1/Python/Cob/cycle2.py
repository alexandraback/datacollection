import sys
f = sys.stdin

cases = int(f.readline())
for caseno in range(1, cases + 1):
    (a, b) = tuple(map(int, f.readline().split()))
    cnt = 0
    for i in range(a, b + 1):
        s = str(i)
        used = set([])
        for j in range(len(s) - 1):
            s = s[-1] + s[0:len(s) - 1]
            if s[0] == '0':
                continue
            lp = int(s)
            if lp in used:
                continue
            if lp > i and a <= lp <= b:
                used.add(lp)
                cnt += 1
    print("Case #{0}: {1}".format(caseno, cnt))
    
        