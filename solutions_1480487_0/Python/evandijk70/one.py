#!/usr/bin/python

f=open("A-small-attempt2.in")

text=f.read()
lines=text.split("\n")

i=1
for line in lines[1:len(lines)-1]:
  Numbers=line.split(" ")
  Ncont=int(Numbers[0])
  Judge=range(1,len(Numbers))
  #print Ncont
  for j in range(1,len(Numbers)):
    Judge[j-1]=int(Numbers[j])
  TarScore=2.*sum(Judge)/(Ncont)
  s=""
  LeftOver=0
  Count=0
  for J in Judge:
    a = (TarScore-J)
    LeftOver+= max(0,-a)
    if(max(0,-a)>0):
      Count+=1
  
  TarScore-=LeftOver/(Ncont-Count)
  for J in Judge:
    a= 100.*(TarScore-J)/sum(Judge)
    s+=str(max(0.,a))
    s+=" "
  print 'Case #{0}: {1}'.format(i,s[0:len(s)-1])
  i+=1
  
  
 # for Cont in Judge:
    #print(sum(Judge))
    #print Cont,sum(Judge)
