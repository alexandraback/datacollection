#!/usr/bin/python2

#from math import sqrt

#inf = open("cons.in1");
#inf = open("A-small-attempt0.in");
inf = open("A-large.in");

vow = ['a','e','i','o','u'];

def compute(L, n):
#   print "\n",L,n;
   k = len(L);
   if n==0:
      return k*(k+1)/2;
   i = -1;
   j = 0;
   c = 0;
   tot = 0;
   while j<k:
      if L[j] not in vow:
         c+=1;
      else: 
         c=0;
      if c==n:
         tot += (k-j)*(j-n-i+1)
         i = j-n+1;
         c-=1;
#      print tot;
      j+=1;
   return tot;
   

T=int(inf.readline());
for t in xrange(T):
   ls = inf.readline().split();
   L=ls[0];
   n=int(ls[1]);
   #print "Case #"+str(t+1)+": %.8f"%compute();
   print "Case #"+str(t+1)+":", compute(L, n);

inf.close();
