R = []
f = open("input.txt","r")
T = int(f.readline())
for k in range(T):
    C, S = map(str, f.readline().strip().split(" "))
    RC = ""
    RS = ""
    ok = 0
    n = len(C)
    for i in range(n):
        print(i, RC,RS)
        c = C[i]
        s = S[i]
        if ok == 0:
            if c == "?" and s == "?":
                if i+1 < n and C[i+1] != "?" and S[i+1] != "?":
                    cn = int(C[i+1])
                    sn = int(S[i+1])
                    if cn > sn:
                        RC += "0"
                        if abs(10+sn-cn) < abs(cn-sn):
                            RS += "1"
                        else:  
                            RS += "0"
                    elif cn < sn:
                        RS += "0"
                        if abs(10+cn-sn) < abs(cn-sn):
                            RC += "1"
                        else:  
                            RC += "0"
                    else:
                        RS += "0"
                        RC += "0"
                else:
                    RC += "0"
                    RS += "0"
            elif c == "?":
                RS += s
                RC += s
            elif s == "?":
                RS += c
                RC += c
            elif c == s:
                RS += s
                RC += s
            elif int(c) > int(s):
                RS += s
                RC += c
                ok = 1
            elif int(c) < int(s):
                RS += s
                RC += c
                ok = -1
        elif ok == 1:
            if c == "?" and s == "?":
                RC += "0"
                RS += "9"
            elif c == "?":
                RS += s
                RC += "0"
            elif s == "?":
                RS += "9"
                RC += c
            else:
                RS += s
                RC += c  
        else:
            if c == "?" and s == "?":
                RC += "9"
                RS += "0"
            elif c == "?":
                RS += s
                RC += "9"
            elif s == "?":
                RS += "0"
                RC += c
            else:
                RS += s
                RC += c    
    R = R + [[RC,RS]]
f.close()



f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k][0])+" "+str(R[k][1])+"\n")
f.close()
