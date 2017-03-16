#!/usr/bin/python3

def search(r, v, s, l):
    if s == l:
        return s
    m = (s + l + 1) // 2
    t = m *( 2 * m + 2 * r - 1)
    if t > v:
        return search(r, v, s, m - 1)
    else:
        return search(r, v, m, l)

t = int(input())
for i in range(t):
    r, t = map(int, input().split())
    print('Case #{}: {}'.format(i+1, search(r,t,0,1000000000)))
