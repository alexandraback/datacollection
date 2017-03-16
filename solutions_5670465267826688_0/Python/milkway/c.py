def find(ss, c, i):
    if i >= len(ss):
        return -1
#    if ss[i] == c:
#        return i + 1
    i += 1
    sign = 1
    while i < len(ss) and (c == 'k' or (ss[i-1] != c or sign != 1)):
        if ss[i-1] == 'i':
            if ss[i] == 'i':
                ss[i] = '1'
                sign *= -1
            elif ss[i] == 'j':
                ss[i] = 'k'
            elif ss[i] == 'k':
                ss[i] = 'j'
                sign *= -1
        elif ss[i-1] == 'j':
            if ss[i] == 'i':
                ss[i] = 'k'
                sign *= -1
            elif ss[i] == 'j':
                ss[i] = '1'
                sign *= -1
            elif ss[i] == 'k':
                ss[i] = 'i'
        elif ss[i-1] == 'k':
            if ss[i] == 'i':
                ss[i] = 'j'
            elif ss[i] == 'j':
                ss[i] = 'i'
                sign *= -1
            elif ss[i] == 'k':
                ss[i] = '1'
                sign *= -1
#        print ss, i, sign
        i += 1
    if ss[i-1] == c and sign == 1:
        return i
    return  -1

def solve():
    l, rep = map(int, raw_input().split())
    [s] = raw_input().split()
    ss = ""
    for _ in xrange(rep):
        ss += s

    sss = []
    for i in ss:
        sss.append(i)

    j = find(sss, 'i', 0)
    if j < 0:
        return "NO"
    k = find(sss, 'j', j)
    if k < 0:
        return "NO"
    ret = find(sss, 'k', k)
#   print j, k, ret, len(sss), len(s), rep
    if ret == len(sss):
        return "YES"
    else:
        return "NO"

T = input()
for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve())
