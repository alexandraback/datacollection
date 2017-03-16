input();print("Case #1:");n,j=map(int,input().split())
for i in range(j):print("".join(c*2 for c in bin((1<<n//2-2)+i)[2:]+"1"),*range(3,12))
