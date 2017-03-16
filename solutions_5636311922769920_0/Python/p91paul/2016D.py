n = int(input())
for i in range(n):
    k = int(input().split(' ')[0])
    print("Case #%d: %s"%(i+1," ".join([str(i) for i in range(1,k+1)])))
