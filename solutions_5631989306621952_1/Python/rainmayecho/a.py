def g(s):
    r = s[0]
    for c in s[1:]:
        if ord(c) >= ord(r[0]):
            r = c + r
        else:
            r += c
    return r

h = open('a_out.txt', 'w')
f1 = 'test.txt'
f2 = 'alarge.in'

with open(f2, 'r') as f:
    T = f.readline()
    for i, e in enumerate(f.readlines()):
        r = g(e.strip())
        print 'Case #%s: %s' %(i+1, r)
        h.write('Case #%s: %s\n' %(i+1, r))

