#!/usr/bin/python
from collections import defaultdict
import array

#f = open('c_gwall_sample.txt')
f = open('C-small-attempt0.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('c_gwall_small_result.txt', 'w')

prob = 0.0
for i in range (0,numcase):
  inputline = f.readline()
  linelist = inputline.split()
  ntribe = int(linelist[0])
  attack_dict = defaultdict(list)
  walls=array.array('i',(0,)*2000001)
  answer = 0
  for j in range(0,ntribe):
    inputline = f.readline()
    linelist = inputline.split()
    day = int(linelist[0])
    nattack = int(linelist[1])
    west = int(linelist[2])
    east = int(linelist[3])
    strength = int(linelist[4])
    delta_d = int(linelist[5])
    delta_p = int(linelist[6])
    delta_s = int(linelist[7])
    for k in range(0,nattack):
      newattack = [west + (k * delta_p), east + (k* delta_p), 
        strength + (k * delta_s)]
      attack_dict[day+ (k * delta_d)].append(newattack)
  sorted_dict = sorted([(key,value) for (key,value) in attack_dict.items()])
  for j in sorted_dict:
    fixwall = []
    for k in j[1]:
      cwest = k[0] + 1000000
      ceast = k[1] + 1000000
      cstr  = k[2]
      #print " day=",j[0]," params=",k
      #print " wallstate=",walls[1000000:1000010]
      for p in range(cwest,ceast):
        if walls[p] < cstr:
          answer +=1
          #print "breached"
          fixwall.append([cwest,ceast,cstr])
          break

    for k in fixwall:
      for p in range(k[0],k[1]):
        if walls[p] < k[2]:
          walls[p] = k[2]

  answ_sentence = "Case #"+str(i+1)+": "+ str(int(answer))
  fout.write(answ_sentence)
  fout.write('\n')
  print answ_sentence