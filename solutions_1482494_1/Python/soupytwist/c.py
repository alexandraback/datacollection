#!/usr/bin/python

def main():
    with open("B-large.in") as f:
        T = int(f.readline().strip())

        for Tcur in range(1, T+1):
            L = int(f.readline().strip())
            lvls = []
            for i in range(L):
                lvls.append([int(x) for x in f.readline().strip().split()])
            moves = foo(lvls, 0, 0)
            if moves == -1:
                print "Case #%d: Too Bad" % Tcur
            else:
                print "Case #%d: %d" % (Tcur, moves)

        f.close()

def foo(lvls, S, M):
    while True:
        lc = len(lvls)
        if lc == 0:
            return M
        bx = 0
        first = True
        stopNow = False

        for i in range(lc):
            if lvls[i][1] <= S:
                l = lvls.pop(i)
                M+=1
                stopNow = True
                if l[0] == -1:
                    #return foo(lvls, S+1, M+1)
                    S+=1
                else:
                    S+=2
                    #return foo(lvls, S+2, M+1)
                break

            elif lvls[i][0] != -1 and lvls[i][0] <= S and (first or lvls[i][1] > lvls[bx][1]):
                first = False
                bx = i

        if not stopNow:
            if lvls[bx][0] <= S and lvls[bx][0] != -1:
                lvls[bx][0] = -1
                S += 1
                M += 1
            else:
                return -1

if __name__=="__main__":
    main()
