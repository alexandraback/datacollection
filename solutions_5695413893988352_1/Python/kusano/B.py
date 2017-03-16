def solve(C, J):
    n = len(C)
    ans = ("0"*n, "9"*n)

    for p in range(n+1):
        for d in (-1, 1):
            c, j = "", ""

            for i in range(p):
                if C[i]=="?" and J[i]=="?":
                    c += "0"
                    j += "0"
                elif C[i]==J[i]:
                    c += C[i]
                    j += J[i]
                elif C[i]=="?":
                    c += J[i]
                    j += J[i]
                elif J[i]=="?":
                    c += C[i]
                    j += C[i]
                else:
                    c += "x"
                    j += "x"

            if p<n:
                i = p
                if C[i]=="?" and J[i]=="?":
                    if d==-1:
                        c += "0"
                        j += "1"
                    else:
                        c += "1"
                        j += "0"
                elif C[i]==J[i]:
                    c += "x"
                    j += "x"
                elif C[i]=="?":
                    j += J[i]
                    if d==-1 and J[i]!="0":
                        c += str(int(J[i])-1)
                    elif d==1 and J[i]!="9":
                        c += str(int(J[i])+1)
                    else:
                        c += "x"
                elif J[i]=="?":
                    c += C[i]
                    if d==-1 and C[i]!="9":
                        j += str(int(C[i])+1)
                    elif d==1 and C[i]!="0":
                        j += str(int(C[i])-1)
                    else:
                        j += "x"
                else:
                    if (d==-1 and C[i]<J[i] or
                        d==1  and C[i]>J[i]):
                        c += C[i]
                        j += J[i]
                    else:
                        c += "x"
                        j += "x"

            for i in range(p+1, n):
                if C[i]=="?":
                    c += "9" if d==-1 else "0"
                else:
                    c += C[i]
                if J[i]=="?":
                    j += "0" if d==-1 else "9"
                else:
                    j += J[i]

            #print p, d, c, j
            if c.count("x")==0 and j.count("x")==0:
                if ((abs(int(c     )-int(j     )), c,      j     ) <
                    (abs(int(ans[0])-int(ans[1])), ans[0], ans[1])):
                    ans = (c, j)
    
    return " ".join(ans)

for t in range(input()):
    C, J = raw_input().split()
    print "Case #%s: %s" % (t+1, solve(C, J))
