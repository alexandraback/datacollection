#!/usr/bin/python

visited=[];
inh = []

def search(x,col):
   if visited[x]==col: 
      return True;
   visited[x]=col;
   for it in inh[x]:
      if search(it,col): 
         return True;
   return False;

def solve(n):
   #for it in inh:
   #   print it;
   for i in xrange(n):
      if search(i,i): return "Yes";
   return "No";

import sys
sys.setrecursionlimit(1000001);

#inF=open("A-small-attempt0.in");
#outF=open("A-small-attempt0.out","w");
inF=open("A-large.in");
outF=open("A-large.out","w");
TC=int(inF.readline());
for tc in xrange(TC):
   ls=inF.readline().split();
   n=int(ls[0]);
   inh=[];
   visited=[-1]*n;
   for i in xrange(n):
      ls=inF.readline().split();
      m=int(ls.pop(0));
      inh.append([int(it)-1 for it in ls[:m]]);
   outF.write("Case #"+str(tc+1)+": "+str(solve(n))+"\n");

inF.close();
outF.close();
