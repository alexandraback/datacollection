#!/usr/bin/python

def solve(n,ju):
   juS=0.+sum(ju);
   juOr=list(ju)
   ju.sort();
   ju.append(juS*2)
   i=1;
   has =1.;
   while has>0:
      dif =ju[i]-ju[i-1];
      if dif*i/juS>=has:
         limit = has*juS/i+ju[i-1];
         has=0;
      else:
         has-=dif*i/juS;
      i+=1;
   res=""
   for i in xrange(n):
      res+=str(max((limit-juOr[i])/juS,0)*100)+" ";
   return res[:-1];
          

inF=open("A-small-attempt0.in");
outF=open("A-small-attempt0.out","w");
#inF=open("A-large.in");
#outF=open("A-large.out","w");
TC=int(inF.readline());
for tc in xrange(TC):
   ls=inF.readline().split();
   n=int(ls[0]);
   ju=[]
   for i in xrange(n):
      ju.append(float(ls[i+1]));
   outF.write("Case #"+str(tc+1)+": "+str(solve(n,ju))+"\n");

inF.close();
outF.close();
