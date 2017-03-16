#!/usr/bin/python

f=open("C-small-attempt0.in")

text=f.read()
lines=text.split("\n")

i=1


for line in lines[1:len(lines)-1]:
  arr=range(1,300000)
  AOfLists=range(1,300000)
  Numbers=line.split(" ")
  Ncont=int(Numbers[0])
  Judge=range(1,len(Numbers))
 
  #print Ncont
  print 'Case #{0}:'.format(i)
  for j in range(1,len(Numbers)):
    Judge[j-1]=int(Numbers[j])
  for J in Judge:
    arr[J]=-1
    AOfLists[J]=[J]
  for J in Judge:
    flag=0
    for J2 in Judge:
      if J<=J2:
        continue
      if arr[J+J2] <0:
        flag=1
        s=""
        for A in AOfLists[J+J2]:
          s+=str(A)
          s+=" "
        print s[0:len(s)-1]
        print J,J2        
        break
      else: 
        arr[J+J2]=-1
        AOfLists[J+J2]=[J,J2]
    if flag==1:
      break
  if flag==1: 
    i+=1
    continue
  for J in Judge:
    flag=0
    for J2 in Judge:
      if J<=J2:
        continue
      for J3 in Judge:
        if J2 <=J3:
          continue
        if arr[J+J2+J3] <0:
          flag=1
          s=""
          for A in AOfLists[J+J2+J3]:
            s+=str(A)
            s+=" "
          print(s[0:len(s)-1])
          print J,J2,J3        
          break
        else: 
          arr[J+J2+J3]=-1
          AOfLists[J+J2+J3]=[J,J2,J3]
      if flag==1:
        break
    if flag==1:
      break
  i+=1
