from operator import itemgetter

a='ejp mysljylc kd kxveddknmc re jsicpdrysi'
b='our language is impossible to understand'

mapDict={}

for i in range(0,len(a)):
    mapDict[a[i]]=b[i]

a='rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
b='there are twenty six factorial possibilities'

for i in range(0,len(a)):
    mapDict[a[i]]=b[i]

a='de kr kd eoya kw aej tysr re ujdr lkgc jv'
b='so it is okay if you want to just give up'

for i in range(0,len(a)):
    mapDict[a[i]]=b[i]

mapDict['z']='q'
mapDict['q']='z'

f=open('aa1','r')
f2=open('out','w')

num=int(f.readline().strip())

for i in range(0,num):
    ostr=''
    for c in f.readline().strip():
        ostr+=mapDict[c]
    print "Case #",i+1,': ',ostr
    f2.write('Case #%d: %s\n' % (i+1,ostr))

f2.close()
