def gc(s):
    v = [0] * 26
    for ch in s:
        v[ord(ch) - ord('A')] += 1
    return v
def f(c, v, d, l):
    x = c[ord(l) - ord('A')]
    v += [d] * x
    for i in range(26):
        c[i] -= x * dwc[d][i]

dw = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
dwc = [gc(d) for d in dw]
for t in range(int(input())):
    c, v = gc(input()), []
    f(c, v, 6, 'X')
    f(c, v, 2, 'W')
    f(c, v, 0, 'Z')
    f(c, v, 8, 'G')
    f(c, v, 7, 'S')
    f(c, v, 4, 'U')
    f(c, v, 1, 'O')
    f(c, v, 5, 'F')
    f(c, v, 9, 'I')
    f(c, v, 3, 'T')
    print('Case #{}: {}'.format(t + 1, ''.join(map(str, sorted(v)))))
