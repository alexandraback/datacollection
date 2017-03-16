def ans(c, w):
    return ((c + w - 1) // w) + w - 1
d = {}
for i in range(1, 11):
    d[(i, 1)] = i
t = int(input())
for case in range(1, t + 1):
    r, c, w = map(int, input().split())
    if r == 1:
        print('Case #', case, ': ', ans(c, w), sep = '')
        