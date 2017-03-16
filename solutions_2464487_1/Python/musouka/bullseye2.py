#!/usr/bin/python

#f = open('1a_a_bullseye.txt')
f = open('A-large.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('bullseye_large_result.txt', 'w')



for i in range (0,numcase):
  inputline = f.readline()
  linelist = inputline.split()
  r = int(linelist[0])
  t = int(linelist[1])
  init_area = r * r
  total = 0
  next_r = r+1
  first_black = next_r * next_r
  min_paint = first_black - init_area

  lastn = 0 
  n = 1
  below_t = True
  while (below_t):
    req = n * min_paint + 2* (n) *(n-1)
    #print "n=",n," req=",req
    if req > t:
      if (lastn + 1) == n:
        below_t = False
        total = lastn
      else:
        n = (lastn+n)/2
    else:
      lastn = n
      n = n * 2

  #print "r=",r," t=",t


  answ_sentence = "Case #"+str(i+1)+": "+ str(total)
  fout.write(answ_sentence)
  fout.write('\n')
  print answ_sentence