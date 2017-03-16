import fileinput
import string

ofile = open('out.txt','w')
A = 0
B = 0
count = 0
cases = 0
for line in fileinput.input(): 
     if count == 0:
        cases = int(line)
        count += 1
     elif (count - 1)%2 == 0:
         sp = line.split()
         A = int(sp[0])
         B = int(sp[1])
         count += 1
     else:
         sp = line.split()
         temp = 1
         min = (2*A + B + 1)
         for j in range(1,A+1):
             temp *= float(sp[j-1])
             ex = temp*(A + B -2*j + 1) + (1-temp)*(A+2*B-2*j+2)
             if(ex < min):
                 min = ex
         if((B+2)<min):
             min = (B+2)
         ofile.write("Case #"+str((count-1)/2 + 1)+': '+str(min)+'\n')
         count += 1

ofile.close()
