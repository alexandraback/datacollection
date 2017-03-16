'''
Created on Mar 29, 2012

@author: jreynolds
'''

#============================================

#============================================

infile = "B-small-attempt0.in";
#infile = "B-large-practice.in";
outfile = "B.out";

#'''
with open(infile,"rt") as f: buf = f.readlines();
buf=map(lambda x: x[:-1], buf);
'''
buf = """4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21
""".split("\n");
#'''

t = int(buf[0]); buf=buf[1:];
buf2 = [];
for i in xrange(1,t+1):
    st = map(int,buf[0].split(" ")); buf=buf[1:];
    _,s,p = st[:3];

    buf2.append([s,p,st[3:]]);

with open(outfile,"wt") as f:
    for rnd,(s,p,arr) in enumerate(buf2):
        print arr;
        m = map(lambda x: x%3, arr);

        arr2=[];
        total=0;
        for a,b in zip(arr,m):
            v=a//3;
            """
            if(b==0):
                if(v>=p): total+=1; print "\t%s = (%s,%s,%s) or (%s,%s,%s)\t0\tGOOD"%(a,v,v,v,v-1,v,v+1); continue;
                if(v+1<p):  print "\t%s = (%s,%s,%s) or (%s,%s,%s)\t0\tBAD"%(a,v,v,v,v-1,v,v+1); continue;
            if(b==1):
                print "\t%s = (%s,%s,%s)\t%s"%(a,v,v,v+1,"GOOD" if v+1>=p else "BAD");
                if(v+1>=p): total+=1;
                continue;
            if(b==2):
                if(v+1>=p): total+=1; print "\t%s = (%s,%s,%s) or (%s,%s,%s)\t2\tGOOD"%(a,v,v+1,v+1,v,v,v+2); continue;
                if(v+2<p): print "\t%s = (%s,%s,%s) or (%s,%s,%s)\t2\tBAD"%(a,v,v+1,v+1,v,v,v+2); continue;
            """
            if(b==0):
                if(v>=p): total+=1; continue;
                if(v+1<p): continue;
                if(v-1<0): continue;
            if(b==1):
                if(v+1>=p): total+=1;
                continue;
            if(b==2):
                if(v+1>=p): total+=1; continue;
                if(v+2<p): continue;

            arr2.append([a,b,v]);
        #print;

        arr=arr2;
        arr2=[];
        print "s=%s, p=%s, total=%s+%s"%(s,p,total,min(s,len(arr)));
        print "arr = %s"%(arr);
        for a,b,v in arr:
            if(b==0): print "\t%s = (%s,%s,%s) or (%s,%s,%s)    0"%(a,v,v,v,v-1,v,v+1);
            if(b==2): print "\t%s = (%s,%s,%s) or (%s,%s,%s)    2"%(a,v,v+1,v+1,v,v,v+2);

        st="Case #%d: %s\n"%(rnd+1,total+min(s,len(arr)));
        print st; f.write(st);

#============================================
