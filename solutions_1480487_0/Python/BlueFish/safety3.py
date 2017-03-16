def solve(cont):
 cont2=cont[:]
 cont3=cont[:]
 X=sum(cont3); cont2.sort(); cont3.sort()
 for step in range(1,len(cont3)):
  if sum([cont3[step]-x for x in cont3[:step]])<=X:
   X-=sum([cont3[step]-x for x in cont3[:step]])
   for c in range(step): cont3[c]=cont3[step]
  else: break
 #print cont3
 #print X
 foo=cont3.count(cont3[0])
 for l in range(foo): cont3[l]+=(float(X)/foo)
 cont4=[]
 for l in range(len(cont3)): cont4.append(cont3[l]-cont2[l])
 cont5=[l*100/sum(cont4) for l in cont4]
 #print cont5
 cont6=[]
 for l in cont: cont6.append(cont5[cont2.index(l)])
 return cont6



inp=[x.strip() for x in file('A-small-attempt1.in','rb+').read().split('\n')]
if '' in inp: inp.remove('')

out=file('A-small-attempt1.out','wb+')
for l in range(len(inp)-1):
 line=[int(x) for x in inp[l+1].split(' ')[1:]]
 out.write('Case #'+str(l+1)+': ')
 print 'Case #'+str(l+1)+':',
 for m in solve(line): out.write(str(m)+' '); print str(m),
 out.write('\n')
 print



solve([10,0,20,40])
solve([24,30,21])