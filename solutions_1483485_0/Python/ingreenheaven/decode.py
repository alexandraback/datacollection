a = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'
b = 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
c = 'de kr kd eoya kw aej tysr re ujdr lkgc jv'

ag = 'our language is impossible to understand'
bg = 'there are twenty six factorial possibilities'
cg = 'so it is okay if you want to just give up'

dict = {}

def add(x, y):
    for i in xrange(len(x)):
        dict[x[i]] = y[i]

add(a, ag)
add(b, bg)
add(c, cg)
dict['q'] = 'q'

mapping = open('mapping.txt', 'w')

for left in sorted(dict.iterkeys()):
    mapping.write(left + ' ' + dict.get(left, '#') + '\n')

mapping.close()
