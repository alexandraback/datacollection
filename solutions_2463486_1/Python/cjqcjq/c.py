import bisect
import sys

A = []
def IntSqrt(x):
    lw = 1
    hi = x
    while lw <= hi:
        mid = (lw + hi) / 2
        if mid * mid > x:
            hi = mid - 1
        else:
            lw = mid + 1
    return hi

def LoadData(model):
    for l in open(model, 'r').readlines():
        A.append(int(l))
    A.sort()

def OnlineQuery(a, b):
    ra = IntSqrt(a)
    rb = IntSqrt(b)
    ia = bisect.bisect_right(A, ra) - 1
    ib = bisect.bisect_right(A, rb) - 1
    if A[ia] * A[ia] == a:
        ia -= 1
    #print a, b, ra, rb, ia, ib, A[ia], A[ib]
    return ib - ia

def OfflineQuery(name):
    ic = -1
    for l in open(name, 'r').readlines():
        ic += 1
        if ic == 0:
            continue
        [A, B] = l.split(' ')
        ans = OnlineQuery(int(A), int(B))
        res = 'Case #' + str(ic) + ': ' + str(ans)
        print res
LoadData(sys.argv[1])
OfflineQuery(sys.argv[2])
