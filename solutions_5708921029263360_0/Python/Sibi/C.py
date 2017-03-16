import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

for t in range(T):
    line = iFile.readline().strip().split()
    J = int(line[0])
    P = int(line[1])
    S = int(line[2])
    K = int(line[3])
    
    output = ""
    
    sp_dict = {}
    sj_dict = {}
    pj_dict = {}
    
    lines = 0
    for s in range(1,S+1):
      for p in range(1,P+1):
        for j in range(1,J+1):
          if not (s,p) in sp_dict:
            sp_dict[(s,p)] = 0
          if not (s,j) in sj_dict:
            sj_dict[(s,j)] = 0
          if not (p,j) in pj_dict:
            pj_dict[(p,j)] = 0
        
          if sp_dict[(s,p)] < K and sj_dict[(s,j)] < K and pj_dict[(p,j)] < K:
            sp_dict[(s,p)] += 1
            sj_dict[(s,j)] += 1
            pj_dict[(p,j)] += 1
            output+=(str(j) + " " + str(p) + " " + str(s) + "\n")
            lines += 1
            
    output = str(lines)+"\n"+output
    print("Case #"+str(t+1)+": "+output)
