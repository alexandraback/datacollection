import math

def reverseDigi(digi):
   return digi[::-1]
def check(tmp, N):
   count = 1
   for i in range(int(math.ceil(len(N)/2))):
      if int(N[:i+1]) >= int(reverseDigi(tmp)[:i+1]):
         count += 1
      else:
         break
   for i in range(int(count)):
      if N[:i] < reverseDigi(tmp)[:i]:
         return False
   return True


inFile = open("C:\\Users\\Eric\\Downloads\\infile.in", "r")
outFile = open("C:\\Users\\Eric\\Downloads\\outfile.out", "w")
inString = inFile.readline()
T = int(inString)

for i in range(T):
   N = inFile.readline()[:-1]
   tmp = "1";
   count = 0

   while tmp != N:
      if len(N) > len(tmp) and tmp[len(tmp) - 1] == "9" and int(tmp) < int(reverseDigi(tmp)) <= int(N):
         #print(i, tmp, N, len(N))
         tmp = reverseDigi(tmp)
      elif len(N) == len(tmp) and check(tmp, N) and int(tmp) < int(reverseDigi(tmp)) <= int(N):
         #print(i, tmp, N, len(N))
         tmp = reverseDigi(tmp)
      else:
         tmp = str(int(tmp)+1)
      count += 1
      #print(i, tmp, N, len(N))
   print(i)
        
   outFile.write("Case #"+str(i+1)+": "+str(count + 1) + '\n')
            
outFile.close()
inFile.close()
