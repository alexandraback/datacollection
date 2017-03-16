#! /usr/bin/python -tt 

T = input()
f = open("out", "w")
for Case in range(1, T+1):
    N = input()
    req = []
    for i in range(N):
        aLine = raw_input()
        aLine = aLine.split()
        tmp1 = eval(aLine[0])
        tmp2 = eval(aLine[1])
        req.append((tmp1, tmp2))
    toobad = False
    star = 0
    step = N
    req = sorted(req, key=lambda aReq: aReq[1])
    while len(req) > 0:
        #print req
        delete = False
        nDel = 0
        for i in range(len(req)):
            ii = i - nDel
            if req[ii][1] <= star:
                if req[ii][0] >= 0:
                    star += 2
                else:
                    star += 1
                delete = True
                nDel += 1
                del req[ii]
        if delete == True:
            continue
        delete = False
        for j in range(len(req)-1, -1, -1):
            if req[j][0] <= star and req[j][0] >= 0:
                star += 1
                delete = True
                req[j] = (-1, req[j][1])
                step += 1
                break
        if delete == True:
            continue
        else:
            toobad = True
            break
    print step, toobad
    if toobad:
        f.write("Case #%d: Too Bad\n" % (Case))
    else:
        f.write("Case #%d: %d\n" % (Case, step))
