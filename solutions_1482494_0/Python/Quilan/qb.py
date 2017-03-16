
#============================================

#============================================

from argparser import parse;

infile = "B-small-attempt1.in";
#infile = "B-large-practice.in";
outfile = "B.out";

#'''
with open(infile,"rt") as f: buf = f.readlines();
buf=map(lambda x: x[:-1], buf);
'''
buf = """4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6 
""".split("\n");
#'''

t = int(buf[0]); buf=buf[1:];
buf2 = [];
for i in xrange(1,t+1):
    n, = parse(buf[0],"i"); buf=buf[1:];
    w = [parse(buf[i],"ii") for i in xrange(n)]; buf=buf[n:];

    buf2.append([n, w]);

def rec(s,s0,s1):
    if(len(s0)+len(s1)==0): return 0;
    print "s0=%s, s1=%s"%(s0,s1);
    
    m1 = filter(lambda x: w[x][0]<=s, s0);
    m2a = filter(lambda x: w[x][1]<=s, s0);
    m2b = filter(lambda x: w[x][1]<=s, s1);
    
    print "m1=%s, m2a=%s, m2b=%s"%(m1,m2a,m2b);
    
    if(len(m2a)>0):
        r=m2a[0];
        v=rec(s+2,s0-set([r]),s1);
        if(v<0): return -1;
        return v+1;

    if(len(m2b)>0):
        r=m2b[0];
        v=rec(s+1,s0,s1-set([r]));
        if(v<0): return -1;
        return v+1;

    if(len(m1)==0): return -1;

    tv=10000;
    for r in m1:
        v=rec(s+1,s0-set([r]),s1|set([r]));
        if(v<0): return -1;
        tv=min(tv,v+1);

    return tv;

with open(outfile,"wt") as f:
    tv=0;
    for rnd,(_,w) in enumerate(buf2):
        w = sorted(w);
        print "w = %s"%w;
        
        s0=set([i for i in xrange(len(w))]);
        s1=set([]);
        t=rec(0,s0,s1);
        st="Case #%d: %s\n"%(rnd+1,"Too Bad" if t<0 else t);
        print st; f.write(st);
        continue;

        s=0;
        t=0;
        s0=set([i for i in xrange(len(w))]);
        s1=set([]);
        s2=set([]);
        i2=0;
        while True:
            print "s=%s\ts0=%s\ts1=%s\ts2=%s"%(s,s0,s1,s2);

            #can immediately get rid of normal
            c = filter(lambda i: w[i][1]<=s, s0);
            if(len(c)>0):
                r=c[0];
                s0.remove(r);
                t+=1; s+=2;
                print "Getting rid of 2: %s\t%s"%(r,w[r]);
                continue;

            #can get rid of from deferred list
            c = filter(lambda i: w[i][1]<=s, s2);
            if(len(c)>0):
                r=c[0];
                s2.remove(r);
                s0 |= s2;
                s2 = set([]);
                t+=1; s+=1;
                print "Getting rid of s2: %s\t%s"%(r,w[r]);
                continue;

            #can increment from normal list
            c = set(filter(lambda i: w[i][0]<=s, s0));
            if(len(c)>0):
                s2 |= c;
                s0 -= c;
                s+=1;
                t+=1;
                continue;

            print "Argh";

            break;

        tv+=t;
        
        st="Case #%d: %s\n"%(rnd+1,"Too Bad" if t<0 else t);
        print st; f.write(st);
    print "tv = %s"%tv;

#============================================
