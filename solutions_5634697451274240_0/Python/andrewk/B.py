
def flip(L,x):
    nL=[L[i] for i in range(x,-1,-1)]
    for i in range(x+1,len(L)): nL.append(L[i])
    for i in range(0,x+1): nL[i] = not nL[i]
    return nL

D={'+':True,'-':False}

for case in range(1, int(input())+1):
    arr=[D[s] for s in input()]
    cnt = 0
    for i in range(0,len(arr)-1):
        if arr[i] != arr[i+1]:
            arr = flip(arr, i)
            cnt+=1
    if arr[0] == False:
        cnt += 1
    print("Case #"+str(case)+": "+str(cnt))
