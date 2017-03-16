#!/usr/bin/python

import sys

numcases=int(sys.stdin.readline())
for j in range(numcases):
  lin=sys.stdin.readline().split()
  r=int(lin[0])
  c=int(lin[1])
  m=int(lin[2])
  sys.stdout.write("Case #"+repr(j+1)+":\n")
  empty=r*c-m
  if empty==0:
    sys.stdout.write("Impossible\n")
  elif empty==1:
    #Always win by picking the only empty space
    sys.stdout.write("c"+"*"*(c-1)+"\n"+("*"*c+"\n")*(r-1))
  elif c==1:
    #Always win when all the empty spaces are at the top
    sys.stdout.write("c\n"+".\n"*(empty-1)+"*\n"*m)
  elif r==1:
    #Always win when all the empty spaces are at the left
    sys.stdout.write("c"+"."*(empty-1)+"*"*m+"\n")
  elif r==2:
    #If the number of empty spaces is even and at least 4, win
    #when the first empty/2 columns are completely empty;
    #otherwise impossible.
    if empty>=4 and empty%2==0:
      ecol=empty/2
      sys.stdout.write("c"+"."*(ecol-1)+"*"*(c-ecol)+"\n")
      sys.stdout.write("."*ecol+"*"*(c-ecol)+"\n")
    else:
      sys.stdout.write("Impossible\n")
  elif c==2:
    #Ditto for rows
    if empty>=4 and empty%2==0:
      erow=empty/2
      sys.stdout.write("c"+"."*(c-1)+"\n")
      sys.stdout.write(("."*c+"\n")*(erow-1))
      if r>erow:
        sys.stdout.write(("*"*c+"\n")*(r-erow))
    else:
      sys.stdout.write("Impossible\n")
  elif empty in (2,3,5,7):
    sys.stdout.write("Impossible\n")
  elif empty>=2*c+2:
    #Win by filling as many full rows of empties as possible,
    #plus a partial row if needed. If the partial row would
    #have only one empty space, put a mine at the end of the
    #penultimate row and two empties in the last row.
    if empty%c==1:
      erow=(empty-1)/c-1
      sys.stdout.write("c"+"."*(c-1)+"\n")
      sys.stdout.write(("."*c+"\n")*(erow-1))
      sys.stdout.write("."*(c-1)+"*\n")
      sys.stdout.write(".."+"*"*(c-2)+"\n")
      if r>erow+2:
        sys.stdout.write(("*"*c+"\n")*(r-erow-2))
    else:
      erow=int(empty/c)
      partrow=empty%c
      sys.stdout.write("c"+"."*(c-1)+"\n")
      sys.stdout.write(("."*c+"\n")*(erow-1))
      if m>0:
        sys.stdout.write("."*partrow+"*"*(c-partrow)+"\n")
      if r>erow+1:
        sys.stdout.write(("*"*c+"\n")*(r-erow-1))
  else:
    #In all other cases, the number of empty spaces is at most
    #three rows minus 2 spaces, and we can win by placing all
    #the empty spaces in a rectangle three rows tall, with one
    #or two mines at the end of the third row if it isn't a
    #multiple of 3.
    if empty%3==0:
      row1=empty/3
      row3=row1
    elif empty%3==1:
      row1=(empty+2)/3
      row3=row1-2
    elif empty%3==2:
      row1=(empty+1)/3
      row3=row1-1
    sys.stdout.write("c"+"."*(row1-1)+"*"*(c-row1)+"\n")
    sys.stdout.write("."*row1+"*"*(c-row1)+"\n")
    sys.stdout.write("."*row3+"*"*(c-row3)+"\n")
    if r>3:
      sys.stdout.write(("*"*c+"\n")*(r-3))
   
