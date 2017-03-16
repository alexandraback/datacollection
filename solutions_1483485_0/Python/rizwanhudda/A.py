import sys
sin = ['ejp mysljylc kd kxveddknmc re jsicpdrysi',
       'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
       'de kr kd eoya kw aej tysr re ujdr lkgc jv']
sout = ['our language is impossible to understand',
        'there are twenty six factorial possibilities',
        'so it is okay if you want to just give up']
a = {'q':'z','z':'q','y':'a','e':'o'}
for i in range(3):
    for c1,c2 in zip(sin[i],sout[i]):
        a[c1] = c2
#b = a.keys()
#b.sort()
#for k in b:
#    print k, a[k]
t=int(sys.stdin.readline().strip())
for i in range(1,t+1):
    s='Case #'+str(i)+": "
    c=sys.stdin.readline().strip()
    for ch in c:
        s+=a[ch]
    print s



