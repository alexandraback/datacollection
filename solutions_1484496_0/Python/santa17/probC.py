#!/usr/bin/python

a=set();

def isS(su,i,nums):
   if i>=len(nums):return ["",5];

   if su+nums[i] in a:
      return [str(nums[i]),su+nums[i]];
   a.add(su+nums[i]);
   [retS, retN] = isS(su,i+1,nums);
   if retS!="": return [retS,retN];
   [retS,retN] = isS(su+nums[i],i+1,nums);
   if retS!="": return [retS+" "+str(nums[i]),retN];
   return ["",0]

def solve(n,nums):
   [retS,retN] = isS(0,0,nums);
   if retS=="": return "Impossible";
   a.clear();
   a.add(retN);
   [retS2,retN] = isS(0,0,nums);
   return retS.rstrip()+"\n"+retS2.rstrip();

inF=open("C-small-attempt0.in");
outF=open("C-small-attempt0.out","w");
#inF=open("C-large.in");
#outF=open("C-large.out","w");
TC=int(inF.readline());
for tc in xrange(TC):
   a.clear();
   ls=inF.readline().split();
   n=int(ls[0]);
   nums = [int(it) for it in ls[1:1+n]];
   outF.write("Case #"+str(tc+1)+":\n"+str(solve(n,nums))+"\n");

inF.close();
outF.close();
