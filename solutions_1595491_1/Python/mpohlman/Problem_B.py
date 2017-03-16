#!/usr/bin/env python
import math

def normal_best(total):
    best=(total + 2 ) / 3
    return best

def surprising_best(total):
    if total == 0:
        best=0
    else:
        best=min([(total + 4) / 3, 10])
    return best

#for index in range(31):
#    print index,normal_best(index),surprising_best(index)

#infile=open('input_example.in','r')
#infile=open('B-small-attempt0.in','r')
infile=open('B-large.in','r')

line=infile.readline()
T=int(line)
#print T
counter=0
for index in range(T):
    counter = counter + 1
    temp=infile.readline().split()
    N,S,p=[int(i) for i in list(temp[0:3])]
    points=[int(i) for i in temp[3:3+N]]
    #print N,S,p
    #print points
    normal=[normal_best(i) >= p for i in points]
    possible_surprising=[(normal_best(i) < p and surprising_best(i) >= p) for i in points]
    #print normal
    #print possible_surprising
    blah=sum(normal)+min([sum(possible_surprising),S])
    
    print 'Case #%(c)d: %(cm)s' % {"c":counter,"cm":blah}
infile.close()
