def ans(r, c, w):
    add = (r - 1) * ((c + w - 1) // w)
    return ((c + w - 1) // w) + w - 1 + add
d = {}
for i in range(1, 11):
    d[(i, 1)] = i
t = int(input())
for case in range(1, t + 1):
    r, c, w = map(int, input().split())
    print('Case #', case, ': ', ans(r, c, w), sep = '')
        