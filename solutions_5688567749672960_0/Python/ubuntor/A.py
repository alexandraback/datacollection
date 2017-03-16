s = open("in")
n2 = int(s.readline().strip())

o = open("out","w")
#n2 = 1
for i in range(1,n2+1):
    n = int(s.readline().strip())
    #n = 900000
    ans = 1
    #print(n,ans)
    while n > 1:
        nn = str(n)
        nn = int(nn[len(nn)//2:])
        #print(n,ans)
        if nn >= 2:
            ans += nn-1
            n -= (nn-1)
            #print(n,ans)
            if n == 1:
                break
            if str(n) != str(n)[::-1]:
                ans += 1
                n = int(str(n)[::-1])
                #print(n,ans)
        elif nn == 1 and str(n) != str(n)[::-1]:
            ans += 1
            n = int(str(n)[::-1])
            #print(n,ans)
        else:
            n -= 1
            ans += 1       
    #print()
    o.write("Case #"+str(i)+": "+str(ans)+"\n")
'''
999899
999891
198999
198001
100891
100001

999899
999001
100999
100001

99999
99001
10099
10001


'''
