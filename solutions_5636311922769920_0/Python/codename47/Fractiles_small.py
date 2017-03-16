fhr = open("input.in",'r')
f = fhr.readlines()
T = int(f[0].strip())
for i in range(1,T+1):
    K = f[i].strip().split(" ")[0]
    toclean = " ".join(str(j) for j in range(1,int(K)+1))
    print("Case #" + str(i) + ": " + str(toclean))
