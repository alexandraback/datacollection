'''
Created on Mar 29, 2012

@author: jreynolds
'''

#============================================

#============================================

infile = "A-small-attempt1.in";
#infile = "A-large-practice.in";
outfile = "A.out";

#'''
with open(infile,"rt") as f: buf = f.readlines();
buf=map(lambda x: x[:-1], buf);
'''
buf = """3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
""".split("\n");
#'''

t = int(buf[0]); buf=buf[1:];
buf2 = [];
for i in xrange(1,t+1):
    st = buf[0]; buf=buf[1:];

    buf2.append(st);

with open(outfile,"wt") as f:
    atr = "abcdefghijklmnopqrstuvwxyz ";
    tr  = "ynficwlbkuomxsevzpdrjgthaq ";
    tr = {b:a for a,b in zip(atr,tr)};
    
    for rnd,x in enumerate(buf2):
        st = "Case #%d: %s\n"%(rnd+1,"".join(map(lambda y: tr[y],x)));
        print st[:-1]; f.write(st);

#============================================
