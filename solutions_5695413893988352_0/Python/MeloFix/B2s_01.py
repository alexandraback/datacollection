T = int(input())

for LoopC in range(1,T+1):
    C, J = input().split()

    List = []


    def minigo(First,Second,Num):
        c, j = "0","0"
        global C, J
        
        for x in range(Num,len(C)):
#            print(c,j,x)
            if int(c) == int(j):
                if C[x] == J[x] == "?":
                    L = []
                    for a in range(2):
                        for b in range(2):
                            GG = minigo(a,b,x+1)
                            L.append([str(a)+GG[0],str(b)+GG[1]])

                    L.sort(key=lambda x:abs(int(x[0])-int(x[1])))
#                    print(L)
                    try:
                        c += str(L[0][0][0])
                        j += str(L[0][1][0])
                    except Exception:
                        c += '0'
                        j += '0'
                            
                elif C[x] == "?":
                    c += J[x]
                    j += J[x]
                elif J[x] == "?":
                    c += C[x]
                    j += C[x]
                else:
                    c += C[x]
                    j += J[x]
                    
            elif int(c) > int(j):
                if C[x] == J[x] == "?":
                    c += '0'
                    j += '9'
                elif C[x] == "?":
                    c += '0'
                    j += J[x]
                elif J[x] == "?":
                    c += C[x]
                    j += '9'
                else:
                    c += C[x]
                    j += J[x]
                
            elif int(c) < int(j):
                if C[x] == J[x] == "?":
                    c += '9'
                    j += '0'
                elif C[x] == "?":
                    c += '9'
                    j += J[x]
                elif J[x] == "?":
                    c += C[x]
                    j += '0'
                else:
                    c += C[x]
                    j += J[x] 

        return c[1:], j[1:]

        
    List.append(minigo(0,0,0))
    List.append(minigo(0,1,0))
    List.append(minigo(1,0,0))

    List.sort(key=lambda x:abs(int(x[0])-int(x[1])))

    c = List[0][0]
    j = List[0][1]

    print("Case #{}: {}".format(LoopC, c+" "+j))
#    print(C,J)
