from collections import deque

T = int(raw_input())

for case in range(T):
    N = int(raw_input())
    d = False
    cls = []
    for cl in range(N):
        line = raw_input().split()
        cls.append([int(i)-1 for i in line[1:]])
    visited = []
    for i in range(N):
        if i in visited or not len(cls[i]):
            continue
        v = []
        q = deque()
        q.append(i)
        while len(q):
            front = q.popleft()
            for c in cls[front]:
                q.append(c)
                if c in v:
                    d = True
                visited.append(c)
                v.append(c)
            if d:
                break
        if d:
            break
    print "Case #{0}: {1}".format(case+1, d and "Yes" or "No")
