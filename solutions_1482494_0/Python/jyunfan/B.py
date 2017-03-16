from sys import stdin

def calc(t, N, L):
    s = 0
    steps = 0
    AC = [0] * N;
    while s<2*N:
        steps = steps + 1
        earn_2s = False
        highest_require = -1
        suggest = -1
        for i in range(0, N):
            if AC[i] == 2:
                continue
            elif AC[i] == 1:
                if s >= L[i][1]:
                    s += 1
                    AC[i] = 2
                    #print "Get 1 star of 2-star of Level %d" % i
                    #print "stars=%d" % s
                    earn_2s = True
                    break
            else:   # AC[i]==0
                if L[i][1] <= s:
                    s +=2
                    AC[i] = 2
                    earn_2s = True
                    #print "Get 2 stars of 2-star of Level %d" % i
                    #print "stars=%d" % s
                    break
                elif s >= L[i][0]:
                    if L[i][1] > highest_require:
                        highest_require = L[i][1]
                        suggest = i
        if earn_2s == False:
            if suggest < 0:
                break
            s += 1
            AC[suggest] = 1    
            #print "Get 1 start of 1-star of Level %d" % suggest
            #print "stars=%d" % s
    if s == 2*N:
        print "Case #%d: %d" % (t, steps)
    else:
        print "Case #%d: Too Bad" % t

T = int(stdin.readline())
for t in range(1, T+1):
    (A) = stdin.readline()
    A = int(A)
    L = []
    for i in range(0, A):
        L.append(stdin.readline().split())
        L[i][0] = int(L[i][0])
        L[i][1] = int(L[i][1])
    calc(t, A, L)
