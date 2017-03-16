def solve(smax,s):
    total = 0
    invite = 0
    for i in range(int(smax)+1):
        if i>total:
            new_invite = i-total
            invite+=new_invite
            total = i
        total+=int(s[i])
    #print(total)
    return invite
for t in range(int(input())):
    (smax,s) = input().strip().split(" ")
    print("Case #{0}: {1}".format(t+1,solve(smax,s)))
