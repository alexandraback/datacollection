a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

D = dict()
for i in range(len(a)):
    if a[i] != ' ':
        D[a[i]] = b[i]
D['z'] = 'q'
D['q'] = 'z'
D[' '] = ' '

L = [ x.strip() for x in open('in').readlines()]
L.pop(0)
case = 0

for line in L:
    case += 1
    res = ''
    for x in line:
        res += D[x]
    print "Case #%d: %s" % (case, res)
