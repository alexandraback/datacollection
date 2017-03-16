import fileinput
import string
import sys
from operator import itemgetter

ofile = open('out.txt','w')
ifile = open(sys.argv[1])
A = 0
B = 0
count = 0
cases = 0
case = 0
line = ifile.readline()
while (line != ""): 
     if case == 0:
        cases = int(line)
        count += 1
        case = 1
        line = ifile.readline()
     elif case == 1:
         N = int(line)
         count += 1
         case = 2
         #print N
         line = ifile.readline()
     else:
         sp = line.split()
         A = []
         B = []
         C = []
         for j in range(N):
              if j!=0:
                   line = ifile.readline()
              #print line
              sp = line.split()
              A.append((j,int(sp[0])))
              B.append((j,int(sp[1])))
              C.append(0)
         
         A = sorted(A,key=itemgetter(1))
         B = sorted(B,key=itemgetter(1))
         
         stars = 0
         steps = 0
         for j in range(N):
              #print (B[j][1])
              if(B[j][1] > stars):
                   for k in range(N):
                        if(C[A[k][0]] < 1):
                             print (str(j )+' '+str(k) + ' '+str(C[A[k][0]]))
                             if(A[k][1] <= stars):
                                  C[A[k][0]] = 1
                                  stars += 1
                                  steps += 1
                                  if(stars >= B[j][1]):
                                       break
                   if(B[j][1] > stars):
                        ofile.write("Case #"+str((count-1)/2 + 1)+': Too Bad\n')
                        break
                   else:
                        stars += (2 - C[B[j][0]])
                        C[B[j][0]] = 2
                        steps += 1
              else:
                   stars += (2-C[B[j][0]])
                   C[B[j][0]] = 2
                   steps += 1
         if(B[N-1][1] <= stars):          
              ofile.write("Case #"+str((count-1)/2 + 1)+': '+str(steps)+'\n')
         
         count += 1
         case = 1
         line = ifile.readline()
ofile.close()
