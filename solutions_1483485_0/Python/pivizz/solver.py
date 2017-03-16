def make_table(a, b):
    res = {}
    for i in xrange(len(a)):
        res[a[i]] = b[i]
    return res

tr = {'a': 'y', 'o': 'e', 'z': 'q'}
tr.update(make_table('our language is impossible to understand', 'ejp mysljylc kd kxveddknmc re jsicpdrysi'))
tr.update(make_table('there are twenty six factorial possibilities', 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'))
tr.update(make_table('so it is okay if you want to just give up', 'de kr kd eoya kw aej tysr re ujdr lkgc jv'))
tr.update({'q': 'z'}) #last one

trinv = {x:y for y,x in tr.items()}

f = open('A-small-attempt0.in', 'r')
g = open('result0.txt', 'w')
N = int(f.next().strip())
tra = lambda x: trinv[x]

for i in xrange(1,1+N):
    s = f.next().strip()
    r = ''.join(map(tra, s))
    g.write('Case #' + str(i) + ': ' + r + '\n')
g.close()