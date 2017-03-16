import math

def get_order(ch1, ch2):
    if ch1 == ch2:
        return 0
    if ch1 < ch2:
        return -1
    return 1

def best(_s1, _s2, order, pos):
    if (pos == len(_s1)) :
        str1 = ''.join(_s1)
        str2 = ''.join(_s2)
        return (abs(int(str1) - int(str2)), str1, str2)
    s1, s2 = _s1[:], _s2[:]
    if order < 0:
        if s1[pos] == '?':
            s1[pos] = '9'
        if s2[pos] == '?':
            s2[pos] = '0'
        return best(s1, s2, order, pos+1)
    if order > 0:
        if s1[pos] == '?':
            s1[pos] = '0'
        if s2[pos] == '?':
            s2[pos] = '9'
        return best(s1, s2, order, pos+1)
    chs1 = str(s1[pos])
    if s1[pos] == '?':
        chs1 = '0123456789'
    chs2 = str(s2[pos])
    if s2[pos] == '?':
        chs2 = '0123456789'
    sol = None
    for ch1 in chs1:
        for ch2 in chs2:
            s1[pos] = ch1
            s2[pos] = ch2
            subsol = best(s1, s2, get_order(ch1, ch2), pos + 1)
            if not sol or sol > subsol:
                sol = subsol
    return sol

T = int(raw_input())
for cs in xrange(0, T):
    s1, s2 = raw_input().split(' ')
    s1 = list(s1.strip())
    s2 = list(s2.strip())
    sol = best(s1, s2, 0, 0)
    print 'Case #%d: %s %s' % (cs+1, sol[1], sol[2])
