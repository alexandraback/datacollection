import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

for t in range(T):
    line = iFile.readline().strip().split()
    B = int(line[0])
    M = int(line[1])
    
    if 2**(B-2) < M:
      answer = "IMPOSSIBLE"
    else:
      answer = "POSSIBLE"
    
    output = str(answer)
    
    print("Case #"+str(t+1)+": "+output)
    
    if answer == "POSSIBLE":
      print(("{0:b}".format(M-1) + "1").zfill(B))
      for i in range(1,B):
        print(("1"*(B-1-i)).zfill(B))
        
