import sys 
a=["ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"]
b=["our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"]
m = {'q':'z'}
for i in xrange(len(a)):
    for j in xrange(len(a[i])):
        m[a[i][j]] = b[i][j]
m['z']='q'
def translate(s):
    return ''.join(map(lambda x:m[x],s))

data = sys.stdin.readlines()
for i,line in enumerate(data[1:]):
  print "Case #%s: %s"%(i+1,translate(line.strip()))