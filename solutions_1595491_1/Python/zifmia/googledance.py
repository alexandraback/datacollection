f = open("b-large.in", "r")
outf = open("b-large.out", "w")

"""
possible cases given total score T = 3*x + k, 0<=k<=2:

if k=0 then either:
  T=x+x+x   or  T= x-1 + x + x+1  is surprising
   high = x   or high = x+1 with surprise

if k=1 then either:
  T=x+x+ x+1   no other options.  I think.
     high = x+1  no surprises

if k=2 then either:
   T= x+x+ x+2  surprising!   or  T= x+  x+1 + x+1
    high = x+1  or x+2 with surprise

So for each score, I can find the highest score if it is not surprising,
or the highest score with a surprise.

"""

t = int( f.readline() )
for t1 in range(t):
    line = map(int, f.readline().split() )
    n = line[0]
    s = line[1]
    p = line[2]
    totals = line[3:]
    if len(totals) != n:
        print "wrong number of scores"

    count = 0
    s_count = 0
    for i in range(n):
        x = totals[i]//3
        m = totals[i] % 3

        if m==0:
            if x>=p:
                count +=1
            elif x+1==p and x>0:
                s_count += 1
        elif m==1:
            if x+1>=p:
                count +=1
        else:
            if x+1>=p:
                count +=1
            elif x+2==p:
                s_count +=1
    score = count + min(s_count, s)
    outf.write("Case #" + str(t1+1)+": " + str(score) +"\n")
outf.close()
