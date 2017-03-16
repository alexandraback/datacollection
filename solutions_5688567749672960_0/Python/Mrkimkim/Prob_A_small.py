File = open("A-small-attempt0.in","r")
Out = open("output.txt","w")
T = int(File.readline().replace("\n",''))

for z in xrange(T):
       N = int(File.readline().replace("\n",''))
       List = [0] * (N+1)
       for i in xrange(N+1): List[i] = i
       for i in range(1, N):
              Str = str(i)
              Len = len(Str) - 1
              while Len >= 0 and Str[Len] == "0": Len -= 1
              Str2 = ""
              while Len >= 0:
                     Str2 += Str[Len]
                     Len -= 1
              List[i+1] = min(List[i]+1, List[i+1])
              if int(Str2) <= N:
                     List[int(Str2)] = min(List[i]+1, List[int(Str2)])
       print List[N]
       #Out.write("Case #" + str(z+1) + ": " + str(List[N]) + "\n")
File.close()
Out.close()
