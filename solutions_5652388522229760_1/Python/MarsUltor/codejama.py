f=open('A-large.in')
l=f.readlines()[1:]
f.close()
a=1
g=open('a','w+')
def f(n):
 s=set();i=0
 while len(s)<10:
  i+=1
  for d in str(n*i):s.add(int(d))
  if i>1000000:break
 g.write('Case #'+str(a)+': '+('INSOMNIA' if i>1000000 else str(n*i))+'\n')
for n in l:
 f(int(n[:-1]));a+=1
g.close()