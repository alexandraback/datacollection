import os
import math
import pdb

inf = open('input.in','r')
inp = inf.read().split('\n')
inf.close()
T = int(inp.pop(0))

def fake(topic, original, faked, first, second):
    for t in topic:
        if t not in original and t not in faked and t[0] in [x[0] for x in original] and t[1] in [x[1] for x in original]:
            faked += [t]
    if len(filter(lambda x:x not in original and x not in faked, topic))==0:
        return len(faked)
    possible_fake = []
    if len(filter(lambda x:x not in [y[0] for y in original],first))>0:
        f = filter(lambda x:x not in [y[0] for y in original],first)[0]
        for candidate in filter(lambda x:x[0] == f, topic):
            possible_fake += [(candidate, fake(topic, original+[candidate], faked[:], first, second))]
    else:
        f = filter(lambda x:x not in [y[1] for y in original],second)[0]
        for candidate in filter(lambda x:x[1] == f, topic):
            possible_fake += [(candidate, fake(topic, original+[candidate], faked[:], first, second))]
    return max([x[1] for x in possible_fake])

outf = open('output','w')
for i in range(T):
    N = int(inp.pop(0))
    topic = []
    original = []
    for j in range(N):
        topic += [inp.pop(0).split(' ')]
    for t in topic:
        if len(filter(lambda x:x[0]==t[0], topic))==1 or len(filter(lambda x:x[1]==t[1], topic))==1:
            original += [t]
    first = list(set([x[0] for x in topic]))
    second = list(set([x[1] for x in topic]))
    outf.write('Case #%d: %d\n'%(i+1, fake(topic, original, [], first, second)))

outf.close()