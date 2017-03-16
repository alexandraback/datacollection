K = 3
C = 2
S = 3

s = open("salida.txt", 'w')
f = open("D-large.in")

cases = int(f.readline())
for case in xrange(1, cases+1):
    s.write("Case #"+str(case)+": ")
    linea = [int(x) for x in f.readline().split(" ")]
    K = linea[0]
    C = linea[1]
    S = linea[2]
    if K == 1:
        s.write("1\n")
        print "1"
    else :
        if C == 1:
            if S < K:
                s.write("IMPOSSIBLE\n")
                print "IMPOSSIBLE"
            else :
                for i in xrange(1, K+1):
                    s.write(str(i)+" ")
                    print i,
                print
                s.write("\n")
        else :
            if S >= K-1:
                for i in xrange(2, K+1):
                    s.write(str(i)+ " ")
                    print i,
                print
                s.write("\n")
            else :
                s.write("IMPOSSIBLE\n")
                print "IMPOSSIBLE"
s.close()
f.close()