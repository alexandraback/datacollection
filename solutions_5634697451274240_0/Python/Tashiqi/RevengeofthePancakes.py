n=int(input())
res = []
for j in range(n):
    S=input()
    r=0
    for i in range(1,len(S)):
        if S[i]!=S[i-1]:
            r+=1
    if S[-1]=='-':
        r+=1
    print("Case #" + str(j+1) + ": " + str(r))
