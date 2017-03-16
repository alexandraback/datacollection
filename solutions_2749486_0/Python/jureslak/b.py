from collections import deque

t = int(raw_input())

for c in range(t):
    x, y = map(int, raw_input().split())

    v = set()
    r = ''
    q = deque([])
    q.append((0,0,0,""))
    while len(q) > 0:
        a, b, d, s = q.popleft()
        if (a,b,d) in v:
            continue
        v.add((a,b,d))
#        print "Jumped to", a, b, "length", d, "path", s
        if (a, b) == (x, y):
            r = s
            break

        if not s or s[-1] != "N":
            q.append((a, b+d+1, d+1, s+"N"))
        if not s or s[-1] != "S":
            q.append((a, b-d-1, d+1, s+"S"))
        if not s or s[-1] != "W":
            q.append((a-d-1, b, d+1, s+"W"))
        if not s or s[-1] != "E":
            q.append((a+d+1, b, d+1, s+"E"))

    print "Case #{}: {}".format(c+1, r)
