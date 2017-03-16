#!/usr/bin/python
import math

#f = open('energy-sample.txt')
f = open('B-small-attempt0.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('energy_small_result.txt', 'w')



for i in range (0,numcase):
  inputline = f.readline()
  linelist = inputline.split()
  e = int(linelist[0])
  r = int(linelist[1])
  n = int(linelist[2])
  inputline = f.readline()
  linelist = inputline.split()
  vlist = []
  total = 0
  cenergy = e
  for j in range(0,n):
    vlist.append(int(linelist[j]))
  for j in range(0,n):
    #last, spend all
    if j == (n-1):
      total += cenergy * vlist[j]
      break
    min_spend = cenergy + r - e
    if min_spend < 0:
      min_spend = 0
    if e == cenergy:
      lookf = math.ceil(e/(r*1.0))
    else:
      lookf = math.ceil( (e-cenergy) / (r*1.0)) 
    #print " e=",e, "cenergy=",cenergy," r=",r
    #print "  lookf",lookf  

    check_range = min(n-j,lookf)
    #print "  checkrange=",check_range
    if (r == e):
      check_range = 0
    optval = vlist[j]
    steps = 0
    for k in range(j+1, int(check_range)):
      if vlist[k] > optval:
        optval = vlist[k] 
        steps = k-j

    #print "  steps=",steps
    #if vlist[j+1] > vlist[j]:
    if steps > 0:
      can_spend = (steps * r) - e + cenergy
      spent = min(can_spend, cenergy)
      total += spent * vlist[j]
      #spent = min_spend
    else:
      total += cenergy * vlist[j]
      spent = cenergy
    cenergy = cenergy - spent + r
    if cenergy > e:
      cenergy = e

  answ_sentence = "Case #"+str(i+1)+": "+ str(int(total))
  fout.write(answ_sentence)
  fout.write('\n')
  print answ_sentence