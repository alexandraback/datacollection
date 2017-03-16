#!/usr/bin/python

#  inp = map(str.strip, list(open('a-sample.in'))[1:])
inp = map(str.strip, list(open('A-small-attempt0.in'))[1:])
#  inp = map(str.strip, list(open('A-large.in'))[1:])


def solve(S):
    maxes = [('A', -1)] * len(S)
    maxes[0] = (S[0], 0)
    for i, e in enumerate(S):
        if not i:
            continue
        maxes[i] = maxes[i-1]
        e = (e, i)
        if e > maxes[i]:
            maxes[i] = e

    #  print maxes
    S = list(S)
    backwards = []
    for i, e in reversed(list(enumerate(maxes))):
        if e[1] == i:
            backwards.append(e[0])
            S[i] = ''
        #  else:

    #  print S
    #  print backwards
    #  print maxes

    return ''.join(backwards) + ''.join(S)


for t, n in enumerate(inp):
    print 'Case #%d: %s' % (t+1, solve(n))
