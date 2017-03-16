__author__ = 'zoli'


def ioptCalc(wN, rgwK):
    iopt = -1
    dwOpt = 0
    imin = 0
    #could use binary search
    for i, wK in enumerate(rgwK):
        if wK > wN:
            if iopt == -1 or dwOpt > wK - wN:
                iopt = i
                dwOpt = wK - wN
        if wK < rgwK[imin]:
            imin = i
    return iopt if iopt > -1 else imin


def scoreWar(N, rgwN, rgwK):
    score = 0
    rgwK.sort()
    while rgwN:
        wN = rgwN.pop()
        ioptK = ioptCalc(wN, rgwK)
        wK = rgwK.pop(ioptK)
        if wN > wK:
            score += 1
            #print(wN, wK)
    return score


def scoreDWar(N, rgwN, rgwK):
    rgwN.sort()
    rgwK.sort()
    score = 0
    while rgwK:
        wKMax = rgwK.pop(-1)
        wNMax = rgwN[-1]
        if wNMax < wKMax:
            #kill
            rgwN.pop(0)
        else:
            #play
            rgwN.pop(-1)
            score += 1
    return score


def solve(filnIn, filnOut):
    f = open(filnIn)
    fOut = open(filnOut, "w")
    T = int(f.readline())

    for i in range(T):
        N = int(f.readline())
        rgwN = [float(st) for st in f.readline().split()]
        rgwK = [float(st) for st in f.readline().split()]
        scorew = scoreWar(N, rgwN[:], rgwK[:])
        scoredw = scoreDWar(N, rgwN[:], rgwK[:])
        stMsg = "Case #{0}: {1} {2}".format(i + 1, scoredw, scorew)
        print(stMsg)
        fOut.write(stMsg)
        fOut.write("\n")


if __name__ == "__main__":
    solve("sample.in", "sample.out")
    solve("D-small-attempt0.in", "D-small-attempt0.out")
    #    solve("sample.in", "sample.out")
    #    solve("B-small-attempt0.in", "B-small-attempt0.out")
    # 0.9 0.6
    # 0.1 0.3
    # 0.5 0.4
    # Case #3: 0 2

    #[0.3, 0.4, 0.6]
    #[0.6, 0.4, 0.3]