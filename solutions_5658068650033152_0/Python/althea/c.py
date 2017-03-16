import sys 
import string
from collections import *

def intersect(a, b):
	return list(set(a) & set(b))

f = open(sys.argv[1])

fourfour = {1 : 1, 2:2, 3:3, 4:4, 5:4, 6:5, 7:6, 8:6, 9:7, 10:7, 11:8, 12:8, 13:9, 14:10, 15:11, 16:12}
fourfive = { 1 : 1, 2 : 2, 3 : 3, 4 : 4, 5:4, 6:5, 7:6, 8:6, 9:7, 10:7, 11:8, 12:8, 13:9, 14:9, 15:10, 16:10, 17:11, 18:12, 19:13, 20:14 }
three = { 1 : 1, 2 : 2, 3 : 3, 4 : 4, 5:4, 6:5, 7:6, 8:6, 9:7, 10:8, 11:8, 12:9, 13:10, 14:10, 15:11, 16:12, 17:12, 18:13, 19:14, 20:14 }
threethree = {1 : 1, 2:2, 3:3, 4:4, 5:4, 6:5, 7:6, 8:7, 9:8}
threefour = { 1 : 1, 2 : 2, 3 : 3, 4 : 4, 5:4, 6:5, 7:6, 8:6, 9:7, 10:8, 11:9, 12:10}
#1 stone = 1 space
#2 = 2
#3 = 3
#4 = 5
#5 = 6
#6 = 8
#7 = 10
#8 = 12
#9 = 14
#10 = 18
#11 = 20

T = int(f.readline())
for c in xrange(1, T+1): 
 line = f.readline().strip().split()
 K = int(line[2])
 W = min(int(line[0]), int(line[1]))
 L = max(int(line[0]), int(line[1]))
 #print line
 ans = -1
 if W == 1: 
	ans = K
 if W == 2:
    ans = K
 if W == 3:
  if L == 3:
    ans = threethree[K]
  else:
    ans = three[K]
 if W == 4:
  if L ==5:
   ans = fourfive[K]
  else:
   ans = fourfour[K]
    
 print 'Case #' + str(c) + ': ' + str(ans)

