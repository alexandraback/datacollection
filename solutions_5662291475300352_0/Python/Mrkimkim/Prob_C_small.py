File = open("C-small-1-attempt5.in","r")
Out = open("output.txt","w")
T = int(File.readline().replace("\n",''))

for z in xrange(T):
       N = int(File.readline().replace("\n",''))
       List = [] # [Start, Mans, Arrive]
       for i in xrange(N):
              Start, Mans, Arrive = File.readline().replace("\n",'').split(' ')
              Start, Mans, Arrive = int(Start), int(Mans), int(Arrive)
              for j in xrange(Mans): List.append([Start, Arrive + j])

       Ret = 0
       List.sort()
       List.reverse()

       if float(float(360 - List[0][0]) /360 * float(List[0][1])) <= float(float(360 - List[1][0]) /360 * float(List[1][1])):
              if float(float(360 - List[0][0]) /360 * float(List[0][1])) + float(List[0][1]) <= float(float(360 - List[1][0]) /360 * float(List[1][1])): Ret = 1
              else: Ret = 0
       else:
              if float(float(360 - List[1][0]) / 360 * float(List[1][1])) + float(List[1][1]) <= float(float(360 - List[0][0]) /360 * float(List[0][1])): Ret = 1
              else: Ret = 0
       Out.write("Case #" + str(z+1) + ": " + str(Ret) + "\n")
Out.close()
File.close()
