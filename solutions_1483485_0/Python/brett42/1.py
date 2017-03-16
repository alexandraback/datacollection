d={}
i='''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jvyeqz'''
o='''our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give upaozq'''

for x in range(len(i)):
    d[i[x]]=o[x]
    
f=open('A-small-attempt6.in')
cases=int(f.readline())
for c in range(1,cases+1):
    r=''.join([d[x] for x in f.readline()])
    print 'Case #%d: %s'%(c,r),



f.close()
