'''
Created on Mar 29, 2012

@author: jreynolds
'''

#============================================

#============================================

infile = "C-small-attempt0.in";
#infile = "C-large-practice.in";
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
        #if(i%10==0): continue;
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
            

def rec(a,b,mn,mx):
    if(a==0): return 0;

    print "a = %s, b = %s"%(a,b);
    xn,xm=mn//10**b,mx//10**b;
    yn,ym=10**(b-1),10**b-1;
    ct=0;
    xn = max(xn,10**(a-1));
    print "%s%s"%("X"*a,"Y"*b);
    print "\tx from %s -> %s"%(xn,xm);
    for x in xrange(xn,xm+1):
        ymx = (mx-x)//(10**a);      #    X*10 + Y <= 40
        ymn = mn-x*10**b;           #    X*10 + Y >= 10
        ymn = max(yn,ymn,x+1);
        ymx = min(ym,ymx);
        
        if(ymn>ymx): break;
        ct += ymx-ymn+1;
        
        #xmx = mx-y*10**b;           #    X + Y*10 <= 40
        #xmn = (mn-y)//10**b;        #    X + Y*10 >= 10
        
        #X <= Y
        
        #if(x*10**b+ymx < mn): print "*^* %s (%s,%s)\t%s"%(x,ymn,ymx,x*10**a+ymx); continue;
        #if(x*10**b+ymn > mx): print "***"; break;
        
        
        
        print "\t\tx=%s\ty from %s to %s\t%s"%(x,ymn,ymx,"");
    print "\tTotal: %s"%(ct);
    return ct;

with open(outfile,"wt") as f:
    for rnd,(a,b) in enumerate(buf2):
        dig = int(log10(a))+1;
        print a,b;
        
        total=brute(a,b);
        st="Case #%d: %s\n"%(rnd+1,total);
        print st; f.write(st);
        continue;
        #print;
        
        #continue;
        
        total=0;
        i = dig//2;
        total+=rec(i,dig-i,a,b);
        print "\tY>=%s"%(10**(dig-i-1));
        print "\tX + Y*%s <= %s"%(10**i,b);
        print "\tX*%s + Y >= %s"%(10**(dig-i),a);
        print "\tX*%s + Y*%s <= X*%s + Y*%s"%(10**i,10**(dig-i),10**(dig-i),10**i);
        print "\tTotal: %s"%(total);

        print;

#============================================
