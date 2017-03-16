# Python 3.2
# Usage: python c.py < input.in > out.txt

cases = int(input())
for case in range(cases):
    inp = input().split()
    A, B = int(inp[0]), int(inp[1])
    found = 0
    B0 = int(inp[1][0])
    for a in range(A, B):
        sa = str(a)
        l = len(sa)
        a0 = int(sa[0])
        seen = set()
        for i in range(1, l):
            ni = int(sa[i])
            if ni >= a0 and ni <= B0:
                b = int(sa[i:]+sa[:i])
                if b != a and b > a and b <= B and b not in seen:
                    found += 1
                    seen.add(b)
    print("Case #{}: {}".format(case + 1, found))
