# -*- coding: UTF-8 -*-
"""
Problem Statement:


   http://code.google.com/codejam/contest/351101/dashboard#s=p0


   Analysis: Essentially a ....


   1: 
   2: 
   3: 
   

"""

import sys
   
# input file
#if(len(sys.argv) < 2):
    #print "Supply a file input"
    #exit()

#filein = open(sys.argv[1], "r")
##output file
#fileout = open("output.txt","w")
#line = filein.readline()



#test cases
#num_tc = int(line)
#case = 1


#while(line and num_tc != 0):
    ##print "Case #%d: %d %d" % (case, index1, index2) 
    ##print >> fileout, "Case #%d: %d %d" % (case, index1, index2) 
    #case += 1
    #num_tc -= 1
    #line = filein.readline()

estr1 = "our language is impossible to understand" 
estr2 = "there are twenty six factorial possibilities" 
estr3 = "so it is okay if you want to just give up" 
    

gstr1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi" 
gstr2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" 
gstr3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv" 


tdict = {}
tdict['a'] = 'y'
tdict['o'] = 'e'
tdict['z'] = 'q'
tdict['q'] = 'z'


for c,i in enumerate(gstr1):
    tdict[i] = estr1[c]

for c,i in enumerate(gstr2):
    tdict[i] = estr2[c]

for c,i in enumerate(gstr3):
    tdict[i] = estr3[c]


#for i in xrange(97,123):
    #if chr(i) in tdict:
        #print "found %c -> %c | %d -> %d" % (chr(i),tdict[chr(i)],ord(chr(i)),ord(tdict[chr(i)]))
    #else:
        #print "not found %c" % chr(i)


fdict = {}

for c,i in enumerate(gstr1):
    fdict[i] = 1


for c,i in enumerate(gstr2):
    fdict[i] = 1

for c,i in enumerate(gstr2):
    fdict[i] = 1


#for i in xrange(97,123):
    #if chr(i) in fdict:
        #print "found %c" %  chr(i)
    #else:
        #print "not found %c" % chr(i)

nmaps = int(sys.stdin.readline().strip())

print nmaps

for nt in range(1,nmaps+1):
    print "Case #%d: " % nt,
    gstr = sys.stdin.readline().strip()
    estr = ""
    for i in gstr:
        estr += tdict[i]
    print estr

