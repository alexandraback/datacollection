f = open("safety.large.in", "r")

T = int(f.readline())

N = []
S = []

for i in range(0, T):
    s = f.readline().split(" ")
    
    N.append(int(s[0]))
    S.append([])

    for j in range(0, N[i]):
        S[i].append(int(s[1+j]))


f.close()



f = open("safety.out", "w")

for t in range(0, T):

    n = N[t]
    s = S[t]

    X = sum(s)

    f.write("Case #" + str(t + 1) + ":")

    #print
    #print "case " + str(t+1)
    #print s

    for i in range(0, n):
        P = s[i]
        so = sorted(s)
        so_i = so.index(P)

        min_Y = 10000

        for nu in range(so_i+1, n+1):
            Jk = sum(so[0:(nu)])

            Y = (Jk + X - (P*nu)) / float(X*nu)

            #print nu, so[0:(nu)], Y

            if (Y < min_Y and Y >= 0):
                min_Y = Y

                #if (nu < (n-1) and P+X*Y <= so[nu+1]):
                #    break
            else:
                break

        if min_Y == 10000:
            min_Y = 0
        elif min_Y > 1:
            print "alg"

        f.write(" " + str(min_Y*100))
        #print str(min_Y*100)

    f.write("\n")


f.close()

print "done"
