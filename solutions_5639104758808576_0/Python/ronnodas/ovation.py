T = int(input())
for case in range(1,T+1):
    SM,SS = input().split()
    SM = int(SM)
    SS = [int(s) for s in SS]
    ans = 0
    sum = 0
    for i in range(SM):
        sum += SS[i]
        if sum < i+1:
            ans = max(ans,i+1-sum)
    print("Case #",case,": ",ans,sep = '')
