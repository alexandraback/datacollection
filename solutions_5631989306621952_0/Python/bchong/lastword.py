#!/usr/bin/env python2.7

#input and output files
testfile=open("smalltest.txt", 'r')
output=open("smalloutput.txt", 'w')

#number of inputs
numtests=testfile.readline()

finalword=""

j=1

for i in range(int(numtests)):
   S=testfile.readline().rstrip()
   finalword=""
   j=1
   for letter in S:
      if j==1:
	 #first letter
	 finalword=letter
	 j=0
      else:
         #compare letter
	 if letter >= finalword[0]:
	 #if letter is later in the alphabet than current first letter, add to beginning of word
	    finalword = letter + finalword
	 else:
	    finalword = finalword + letter

   output.write("Case #{0}: {1}".format(i+1, finalword))
   output.write("\n")

#close files
testfile.close()
output.close()
