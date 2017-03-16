t = int(input())
for case in range(1, t+1):
    inp = input()
    x = int(inp.split()[0])
    y = int(inp.split()[1])
    i = 0
    j = 0
    c = 1
    s = ''
    if x > 0:
        while i + c <= x:
            i += c
            c += 1
            s += 'E'
    else:
        while i - c >= x:
            i -= c
            c += 1
            s += 'W'
    if y > 0:
        while j + c <= y:
            j += c
            c += 1
            s += 'N'
    else:
        while j - c >= y:
            j -= c
            c += 1
            s += 'S'
    if i != x:
        while i < x:
            i -= c
            c += 1
            s += 'W'
            i += c
            c += 1
            s += 'E'
        while i > x:
            i += c
            c += 1
            s += 'E'
            i -= c
            c += 1
            s += 'W'
    if j != y:
        while j < y:
            j -= c
            c += 1
            s += 'S'
            j += c
            c += 1
            s += 'N'
        while j > y:
            j += c
            c += 1
            s += 'N'
            j -= c
            c += 1
            s += 'S'
    print('Case #%i: %s' % (case, s))
