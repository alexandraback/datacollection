#!/usr/bin/python


f = open('A-small-attempt0.in')
#f = open('A-large.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('a_result_small.txt', 'w')

inh = []
inhgrid = []
numclass = 0


def make_inh_grid():
  global numclass
  global inh
  global inhgrid

  for i in range(0, numclass):
    thisclass = []
    for j in range(0, numclass):
      if j in inh[i]:
	thisclass.append(1)
      else:
	thisclass.append(0)
    inhgrid.append(thisclass)


def find_inh_path(a,b):
  global inh
  #global inhgrid
  global numclass

  #print "a="+str(a)+" b=",str(b)
  found = 0
  for i in range(0, len(inh[a])):
    if inh[a][i] == b:
      #print " direct from="+str(inh[a][i])
      found = found + 1
    else:
      temp = find_inh_path(inh[a][i],b)
      #print " inh_found="+str(temp)
      found = found + temp
    if found > 1:
      return found
  return found


for i in range (0,numcase):
  line = f.readline()
  numclass = int(line)
  inh = []
  for j in range(0,numclass):
    line = f.readline()
    linelist = line.split()
    num_inh = int(linelist[0])
    thisclass = []
    for k in range(1, num_inh+1):
      thisclass.append( int(linelist[k]) - 1 )
    #print "j="+str(j)+" ->"
    #print thisclass
    #print "----------"
    inh.append(thisclass)
  #print inh
  #make_inh_grid()
  inh_found = False
  for j in range(0, numclass):
    if inh_found == True:
      break
    for k in range(0, numclass):
      if j != k:
	# how many inheritance path from k to j
	num = find_inh_path(j,k)
	#print " inh_found="+str(num)
	if num > 1:
	  inh_found = True
	  break


  if inh_found == True:
    answ_sentence = "Case #"+str(i+1)+": Yes"
  else:
    answ_sentence = "Case #"+str(i+1)+": No"

  fout.write(answ_sentence)
  fout.write('\n')
  #print answ_sentence
  #print "Case #"+str(i+1)+": "+ '%.6f' % answer

f.close()
fout.close()

