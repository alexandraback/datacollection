mapping = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v',
'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k',
'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f',
'v': 'p' , 'y': 'a', 'x': 'm', 'z': 'q'} 

casenum = 1
def doit(case):
    global casenum

    print 'Case #%d: %s' % (casenum, ''.join([mapping[c] for c in case]))
    casenum += 1

raw = [x.strip() for x in open('A-small-attempt0.in').readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
