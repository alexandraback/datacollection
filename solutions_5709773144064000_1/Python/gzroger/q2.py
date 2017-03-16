__author__ = 'zoli'
from decimal import *

def tminFor(C, F, X):
    tmin = X/Decimal(2.0)
    n = Decimal(0)
    tCn = Decimal(0.0)
    while True:
        n += Decimal(1)
        tCn += C/(Decimal(2.0)+(n- Decimal(1))*F)
        tX = tCn + X/(Decimal(2)+n*F)
        if tX < tmin:
            tmin = tX
        else:
            return tmin


def solve(filnIn, filnOut):
    f = open(filnIn)
    fOut = open(filnOut, "w")
    T = int(f.readline())

    for i in range(T):
        rgparams = [Decimal(st) for st in f.readline().split()]
        C = rgparams[0]
        F = rgparams[1]
        X = rgparams[2]
        tmin = tminFor(C, F, X)
        stMsg = "Case #{0}: {1:.7f}".format(i + 1, tmin)
        print(stMsg)
        fOut.write(stMsg)
        fOut.write("\n")


if __name__ == "__main__":
    solve("B-large.in", "B-large.out")
#    solve("sample.in", "sample.out")
#    solve("B-small-attempt0.in", "B-small-attempt0.out")