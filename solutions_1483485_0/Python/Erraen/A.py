import sys
input = sys.stdin

m = {'y': 'a',
     'e': 'o',
     'q': 'z'}

mm = {'ejp mysljylc kd kxveddknmc re jsicpdrysi': 'our language is impossible to understand',
      'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd': 'there are twenty six factorial possibilities',
      'de kr kd eoya kw aej tysr re ujdr lkgc jv': 'so it is okay if you want to just give up'}

for sk, sv in mm.iteritems():
    p = -1
    for k in sk:
        p += 1
        if k in m.keys():
            continue
        if sv[p] in m.values():
            print k, sv[p]
        m[k] = sv[p]


nk = None
nv = None
for i in 'qwertyuiopasdfghjklzxcvbnm':
    if i in m.keys():
        continue
    nk = i
    break

for j in 'qwertyuiopasdfghjklzxcvbnm':
    if j in m.values():
        continue
    nv = j
    break

m[nk] = nv
    

def process(data):
    pass

T=int(input.readline())
for i in xrange(1,T+1):
    data = input.readline().strip()
    res = ''.join([m[x] for x in data])
    print 'Case #%s: %s' % (i, res)
