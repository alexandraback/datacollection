#!/usr/bin/python
# vi: set fileencoding=utf-8 :

def rev(x):
    s = str(x)
    s = s[::-1]
    return int(s)


def fewest_count(N):
    x = 1
    dic = {1:True}
    i = 1
    q = []
    while x != N:
        if x + 1 not in dic:
            q.append((x + 1, i + 1))
            dic[x + 1] = True
        y = rev(x)
        if y not in dic:
            q.append((y, i + 1))
            dic[y] = True
        x, i = q.pop(0)
    return i


T = int(raw_input())
for case_number in range(1, T + 1):
    N = int(raw_input())
    print 'Case #%d: %d' % (case_number, fewest_count(N))
