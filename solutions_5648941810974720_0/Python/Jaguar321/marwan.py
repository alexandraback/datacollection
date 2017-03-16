def readInt(): return int(raw_input())
def readList(): return map(int, raw_input().split(' '))

t = readInt()

for l in xrange(t):
    s = list(raw_input())
    n = [0 for i in xrange(10)]
    k = s.count('Z')
    i = 0
    n[0] = k
    o = list("ZERO") * k
    k *= 4
    while k*4 != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    i = 0
    k = s.count('X')
    n[6] = k
    o = list("SIX") * k
    k *= 3

    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('G')
    i = 0
    n[8] = k
    o = list("EIGHT") * k
    k *= 5
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('W')
    i = 0
    n[2] = k
    o = list("TWO") * k
    k *= 3
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('H')
    i = 0
    n[3] = k
    o = list("THREE") * k
    k *= 5
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('R')
    i = 0
    n[4] = k
    o = list("FOUR") * k
    k *= 4
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('F')
    i = 0
    n[5] = k
    o = list("FIVE") * k
    k *= 4
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('V')
    i = 0
    n[7] = k
    o = list("SEVEN") * k
    k *= 5
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    k = s.count('O')
    i = 0
    n[1] = k
    o = list("ONE") * k
    k *= 3
    while k != 0:
        if s[i] in o:
            o.remove(s[i])
            s.pop(i)
            k -= 1
        else:
            i+= 1
    n[9] = s.count('I')
    ans = []

    print "Case #%d:" % (l+1),
    for i in xrange(10):
        ans += [str(i)] * n[i]
    print ''.join(ans)