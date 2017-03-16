#============================================

#============================================

from argparser import parse;

infile = "A-small-attempt0.in";
infile = "A-large.in";
outfile = "A.out";

#'''
with open(infile,"rt") as f: buf = f.readlines();
buf=map(lambda x: x[:-1], buf);
'''
buf = """3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
""".split("\n");
#'''

t = int(buf[0]); buf=buf[1:];
buf2 = [];
for i in xrange(1,t+1):
    a,b = parse(buf[0],"ii"); buf=buf[1:];
    _,p = parse(("%s "%a)+ buf[0],"iF0"); buf=buf[1:];

    buf2.append([a,b,p]);

with open(outfile,"wt") as f:
    for rnd,[k,n,p] in enumerate(buf2):
        gp=1.0;
        good=[1.0];
        for i in xrange(k):
            gp*=p[i];
            good.append(gp);
        
        mv = n+2;
        
        v1, v2 = n-k+1, 2*n-k+2;
        c1 = v1*good[-1] + v2*(1.0-good[-1]);
        #print "c1 = %s"%c1;
        
        mv = min(mv,c1);
        
        for j in xrange(1,k+1):
            v3, v4 = 2*j+n-k+1, 2*j+n-k+1+n+1;
            c2 = v3*good[-1-j] + v4*(1.0-good[-1-j]);
            #print "c2[%d] = %s"%(j,c2);
            mv = min(mv,c2);
        
        c3 = n+2;
        #print "c3 = %s"%(c3);
        
        st="Case #%d: %f\n"%(rnd+1,mv);
        print st; f.write(st);

#============================================
