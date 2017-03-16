'''
Created on Mar 29, 2012

@author: jreynolds
'''

#============================================

#============================================

infile = "C-small-attempt0.in";
infile = "C-large.in";
outfile = "C.out";

#'''
with open(infile,"rt") as f: buf = f.readlines();
buf=map(lambda x: x[:-1], buf);
'''
buf = """4
1 9
10 40
100 500
1111 2222
""".split("\n");
#'''

t = int(buf[0]); buf=buf[1:];
buf2 = [];
for i in xrange(1,t+1):
    a,b = map(int,buf[0].split(" ")); buf=buf[1:];

    buf2.append([a,b]);

from math import log10;

def brute(mn,mx):
    dig=log10(mn)+1;
    dig=int(dig);
    
    print "----";
    pairs=set([]);
    for i in xrange(mn,mx+1):
        x=str(i);
        for j in xrange(1,len(x)):
            st = x[j:]+x[:j]
            if(st[0]=="0"): continue;
            a,b=int(x),int(st);
            if(a>b): a,b=b,a;
            if(a==b): continue;
            if(a<mn or b>mx): continue;
            
            pairs.add((a,b));

    return len(pairs);
    for (a,b) in sorted(pairs): print "%s, %s"%(a,b);

from time import time;

with open(outfile,"wt") as f:
    for rnd,(a,b) in enumerate(buf2):
        dig = int(log10(a))+1;
        print a,b;

        lst=time();
        total=brute(a,b);
        st="Case #%d: %s\n"%(rnd+1,total);
        print "Time taken: %fs"%(time()-lst);
        print st; f.write(st);

        #YEAH, brute force is a pain, but it gets the job done in time!

#============================================
