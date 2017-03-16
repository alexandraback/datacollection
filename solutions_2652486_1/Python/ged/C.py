#!/usr/bin/python
import sys

inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
rnmk = inp[1].split(" ")
R=int(rnmk[0])
N=int(rnmk[1])
M=int(rnmk[2])
K=int(rnmk[3])

l = 2
print "Case #1:"
for t in range(R):
  prods = [int(x) for x in inp[l].split(" ")]
  l += 1
  min7=0
  min5=0
  min4=0
  min3=0
  min2=0
  for x in prods:
  	rest=3
  	m7=0
  	while x%7==0:
  		m7+=1
  		x/=7
  		rest-=1
  	m5=0
  	while x%5==0:
  		m5+=1
  		x/=5
  		rest-=1
  	m3=0
  	while x%3==0:
  		m3+=1
  		x/=3
  		rest-=1
  	m2=0
  	while x%2==0:
  		m2+=1
  		x/=2
  	m4=0
#  	while m2>rest:
#  		m4+=1
#  		m2-=2
#  		rest-=1
  	min7 = max(m7, min7)
  	min5 = max(m5, min5)
  	min4 = max(m4, min4)
  	min3 = max(m3, min3)
#  print prods, min3, min4, min5, min2, "rest?", rest


  s=""
  for i in range(min3):
  	s += '3'
  for i in range(min4):
  	s += '4'
  for i in range(min5):
  	s += '5'
  for i in range(min7):
  	s += '7'
  while len(s)<N:
  	s+='2'
  print s

