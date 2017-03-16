def parse_file(fnIn, fnOut):
    with open(fnOut, 'w') as fOut:
        with open(fnIn, 'rU') as fIn:
            T = int(fIn.readline())

            for n in xrange(T):
                N,M,K = map(int, fIn.readline().split())

                numStones = num_stones(N, M, K)

                print N,M,K
                s = 'Case #%d: %d\n'%(n + 1, numStones)
                fOut.write(s)

                print s


def num_stones(N, M, K):
    # check square
    stonesSquare = 1000*1000
    stonesFilled = 1000*1000

    for n in xrange(1, min(N,M) + 1):
        numStones = 4*n
        internalRect = n**2

        extrasMultiple = 0

        if n < N:
            extrasMultiple += 1
        if n < N - 1:
            extrasMultiple += 1
        if n < M:
            extrasMultiple += 1
        if n < M - 1:
            extrasMultiple += 1

        fromDiamond = extrasMultiple*extras(n)

        totalEnclosed = numStones + internalRect + fromDiamond

        if totalEnclosed >= K:
            stonesSquare = numStones
            break

        remaining = K - totalEnclosed

        if remaining > 0:
            canFillWith = numStones + remaining

            if canFillWith < stonesFilled:
                stonesFilled = canFillWith

    # check rect
    stonesRect = 1000*1000

    for n in xrange(1, N + 1):
        for m in xrange(1, M + 1):
            numStones = 2*n + 2*m

            if numStones >= stonesRect:
                continue

            internalRect = n*m

            fromDiamond = extras(n)*((n < N) + (n < N - 1)) \
                    + extras(m)*((m < M) + (m < M - 1))

            totalEnclosed = numStones + internalRect + fromDiamond

            if totalEnclosed >= K:
                stonesRect = numStones

            remaining = K - totalEnclosed

            if remaining > 0:
                canFillWith = numStones + remaining

                if canFillWith < stonesFilled:
                    stonesFilled = canFillWith

    return min(stonesSquare, stonesRect, stonesFilled, K)


def extras(n):
    return sum(n - v for v in xrange(2, n, 2))

