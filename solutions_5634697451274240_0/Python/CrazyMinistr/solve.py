fi = open('in', 'r')
fo = open('out', 'w')

n = int(fi.readline())
for i in range(n):
    s = list(fi.readline())
    s = s[:-1]
    ans = 0
    while True:
        l = len(s)
        while l > 0 and s[l - 1] == '+':
            l -= 1

        if l == 0:
            break

        s = s[:l]
        if s[0] == '+':
            l = 0
            ans += 1
            while s[l] == '+':
                s[l] = '-'
                l += 1

        ans += 1
        s.reverse()
        s = map(lambda x: '-' if x == '+' else '+', s)
    fo.write('Case #%d: %d\n' % ((i + 1), ans))
