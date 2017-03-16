import fileinput

case = 0
o = 0
for line in fileinput.input("fashion.txt"):
    if o ==0:
        o+=1
    else:
        case+=1
        a = line.split()
        J = int(a[0])
        P = int(a[1])
        S = int(a[2])
        K = int(a[3])
        days = J*P*min([K, S])
        print("Case #"+str(case)+": "+str(days))
        combo = [1, 1, 1]
        k0 = 1
        for i in range(1,J+1):
            k0 = i
            for j in range(1, P+1):
                
                if S<K:
                    for k in range(1, S+1):
                        print(str(i)+" "+str(j)+" "+str(k))
                else:
                    
                    for k in range(K):
                        print(str(i)+" "+str(j)+" "+str(k0))
                        k0+=1
                        if k0 > S:
                            k0 = 1
