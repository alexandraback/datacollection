fhr = open("input.in",'r')
f = fhr.readlines()
T = int(f[0].strip())
for j in range(1,T+1):
    S = f[j].strip()
    ecstatic = 0
    for i in range(0,len(S)-1):
        if S[i] != S[i+1]:
            ecstatic += 1
    if S[-1] == "-":
        ecstatic += 1
    print("Case #" + str(j) + ": " + str(ecstatic))
