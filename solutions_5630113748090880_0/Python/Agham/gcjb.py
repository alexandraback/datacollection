for x in range(int(input())):
    n = int(input())
    q=[0]*2600
    ans=''
    for i in range(2*n-1):
        temp = list(map(int, input().split()))
        for j in (temp):
            q[j]+=1
    for i in range(len(q)):
        if q[i]%2:
            ans +=str(i)+' '
    ans = ans[0:len(ans)-1]
    print('Case #'+ str(x+1)+': '+ans)
