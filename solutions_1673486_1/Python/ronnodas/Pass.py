T=int(input())
for t in range(T):
    a,b = [int(x) for x in input().split()]
    ps = [float(x) for x in input().split()]
    pps = [1]*(a+1)
    #pps[i] = pi_{j=0}^{i-1} ps[j]
    for i in range(a):
        pps[i+1] = pps[i]*ps[i]
    
    case3 = (b+2)
    case2 = case3
    for i in range(a+1):
        case2 = min(case2,(i+i+b-a+1)+(1-pps[-i-1])*(b+1))
    ans = min(case2,case3)
#    print(case1,case2,case3)
    print('Case #',t+1,': ',"%.6f" % ans,sep = '')
