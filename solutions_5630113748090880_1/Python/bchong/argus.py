#!/usr/bin/env python2.7

#input and output files
testfile=open("B-large.in", 'r')
output=open("largeoutput.txt", 'w')

#number of inputs
numtests=testfile.readline()

for i in range(int(numtests)):
   papers={}
   missing=[]
   N=int(testfile.readline().rstrip())

   for j in range((2*(N-1))+1):
      line=testfile.readline().rstrip()
      for number in line.split():
         if papers.has_key(number):
	    papers[number] += 1
	 else:
	    papers[number]=1

   #all nums should have a count of a multiple of 2   
   for key in papers:
      if int(papers[key])%2==1:
         missing.append(int(key))

   missing.sort()

   strmissing=[]

   for item in missing:
      strmissing.append(str(item))

   output.write("Case #{0}: {1}".format(i+1, ' '.join(strmissing)))
   output.write("\n")

#close files
testfile.close()
output.close()
