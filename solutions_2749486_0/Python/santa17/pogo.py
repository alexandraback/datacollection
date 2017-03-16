#!/usr/bin/python2

#from math import sqrt

#inf = open("pogo.in1");
inf = open("B-small-attempt1.in");
#inf = open("B-large.in");

def check(let,ox,oy):
   x=0;
   y=0;
   i=1;
   for it in let:
      if it=='N': y+=i;
      elif it=='S': y-=i;
      elif it=='E': x+=i;
      else: x-=i;
      i+=1;
   if x!=ox or y!=oy: print ox,oy,x,y,"MEGABAD";

def compute(t,x,y):
   ox=x;
   oy=y;
   st = abs(x)+abs(y);
   jui = 0;
   jut = 0;
   while (jut<st) or ((jut-st)%2!=0):
      jui+=1;
      jut+=jui;
   neg = (jut-st)/2;
   #if t==38: print x,y,jut,jui,neg;
   let = ['x']*jui;
   xp = 'E'
   xn = 'W'
   yp = 'N'
   yn = 'S'
   if x<0:
      xn = 'E'
      xp = 'W'
      x=-x;
   if y<0:
      yn = 'N'
      yp = 'S'
      y=-y;
   if x>y:
      x+=neg;
      nl = xn;
   else:
      y+=neg;
      nl = yn;
   i=jui;
   while i>0:
      if i<=neg:
         let[i-1] = nl;
         neg-=i;
      i = min(i-1,neg);
   if x<y:
      do = x;
      fp = xp;
      sp = yp;
   else:
      do = y;
      fp = yp;
      sp = xp;
   can = [-1]*(do+2);
   can[0] = 0;
   maxcan = 1;
   i = 0;
   while i<jui:
      i+=1;
      if let[i-1]!='x':continue;
      for j in xrange(maxcan):
         if can[j]>=0 and can[j]!= i and j+i<=do and can[j+i]<0:
            can[j+i]=i;
            if j+i == do: break;
            maxcan=max(maxcan,j+i+1);
   if can[do]==-1:
      print x,y,jui,jut,neg,"SUPERBAD",let;
      return "";
   while do>0:
      let[can[do]-1]=fp;
      do = do - can[do];
   for i in xrange(jui):
      if let[i] == 'x':
         let[i] = sp;
   check(let,ox,oy);
   return "".join(let);
   

T=int(inf.readline());
for t in xrange(T):
   ls = inf.readline().split();
   x=int(ls[0]);
   y=int(ls[1]);
   #print "Case #"+str(t+1)+": %.8f"%compute();
   print "Case #"+str(t+1)+":", compute(t,x,y);

inf.close();
