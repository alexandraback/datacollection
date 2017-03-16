import sys

fsrc = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
fdst = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""

mp = {}

for i,c in enumerate(fsrc):
    if c in mp:
        if fdst[i]!=mp[c]:
            print "error: %s-> %s %s"%(c,mp[c],fdist[i])
    else: mp[c]=fdst[i]
mp['z']='q'
mp['q']='z'
#print sorted(mp.items())
#print sorted(mp.values())
#print sorted(mp.keys())

f=open(sys.argv[1],'r')
d = f.readlines()
n = int(d[0].strip())
for i,l in enumerate(d):
    if i>n: break
    if i>0:
        print "Case #%d: %s"%(i,''.join([mp[x] for x in l.strip()]))
