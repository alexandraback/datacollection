from itertools import combinations

T = int(raw_input())
for i in range(T):
    tab = []
    N = int(raw_input())
    for j in range(N):
        D, H, M = map(int, raw_input().split())
        for k in range(H):
            tab.append((D, M+k))
    # print tab
    res = 1
    if len(tab)<2:
        res = 0
    else:
        if min([v for d,v in tab])==max([v for d,v in tab]):
            res = 0
        else:
            mavi = min([v for d,v in tab])
            mivi = max([v for d,v in tab])
            if tab[0][1]==mivi:
                mi = 0
            else:
                mi = 1
            ma = 1-mi
            if tab[mi][0]>tab[ma][0]:
                intdep=1
                arrslo = mivi*((360-tab[mi][0])/360.)
                # print arrslo
                tpsquick = mavi + mavi*((360-tab[ma][0])/360.)
                # print tpsquick
                if tpsquick > arrslo:
                    res = 0
                else:
                    res = 1
            else:
                intdep=0
                arrslo = mivi*((360-tab[mi][0])/360.)
                tpsquick = mavi + mavi*((360-tab[ma][0])/360.)
                # print arrslo
                # print tpsquick
                if tpsquick > arrslo:
                    res = 0
                else:
                    res = 1
    print "Case #"+str(i+1)+": "+str(res)
