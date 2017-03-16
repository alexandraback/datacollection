f = open("box.large.in", "r")


T = int(f.readline())


N = []
M = []

A = []
B = []

for i in range(0, T):
    s = f.readline().split(" ")
    
    N.append(int(s[0]))
    M.append(int(s[1]))

    A.append([])
    B.append([])

    s1 = f.readline().split(" ")
    s2 = f.readline().split(" ")

    for j in range(0, N[i]):
        A[i].append((int(s1[2*j]), int(s1[2*j + 1])))

    for j in range(0, M[i]):
        B[i].append((int(s2[2*j]), int(s2[2*j + 1])))


f.close()


mem = {}

def harvest(a, b):
    # no clone, clone before use

    #print a

    po = 0
    
    while (len(a) > 0 and len(b) > 0 and a[0][1] == b[0][1]):
        if (a[0][0] > b[0][0]):
            #print "a", a[0][0], b[0][0]
            p = b[0][0]
            a[0] = (a[0][0] - p, a[0][1])
            del b[0]
        elif (b[0][0] > a[0][0]):
            #print "b"
            p = a[0][0]
            b[0] = (b[0][0] - p, b[0][1])
            del a[0]
        else:
            p = a[0][0]
            #print "c"
            del a[0]
            del b[0]

        po += p

    return po

def maximum(a, b, p0):

    if (len(a) == 0 or len(b) == 0):
        return 0

    aa = list(a)
    bb = list(b)
    
    p = harvest(aa, bb)

    #print "p: " + str(p)
    #print aa
    #print bb
    #print

    la = len(aa)
    lb = len(bb)

    if (la == 0 or lb == 0):
        return p
    elif (mem.has_key((la, lb, aa[0][0], bb[0][0]))):
        #print "yey"
        return mem[(la,lb,aa[0][0],bb[0][0])]
    else:
        slang_a = maximum(aa[1:], bb, p0+p)
        slang_b = maximum(aa, bb[1:], p0+p)

        if (slang_a > slang_b):
            mem[(la,lb,aa[0][0],bb[0][0])] = slang_a + p
        else:
            mem[(la,lb,aa[0][0],bb[0][0])] = slang_b + p

        return mem[(la,lb,aa[0][0],bb[0][0])]
        

f = open("box.out", "w")

for t in range(0, T):

    n = N[t]
    m = M[t]

    a = A[t]
    b = B[t]

    #print a
    #print b
    #print

    ma = maximum(a, b, 0)

    f.write("Case #" + str(t + 1) + ": " + str(ma) + "\n")

f.close()

print "done"
