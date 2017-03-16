def main():
    i = 2
    j = 3
    k = 4
    ma = {
        1: {1: 1, i: i, j: j, k: k},
        i: {1: i, i: -1, j: k, k: -j},
        j: {1: j, i: -k, j: -1, k: i},
        k: {1: k, i: j, j: -i, k: -1},
        -1: {}, -i: {}, -j: {}, -k: {},
    }

    keys = [1,i,j,k]

    for a in keys:
        for b in keys:
            ma[-a][b] = -ma[a][b]
            ma[a][-b] = -ma[a][b]
            ma[-a][-b] = ma[a][b]

    tr = {'i': i, 'j': j, 'k': k}

    for C in range(1, input()+1):
        L, X = map(int, raw_input().split())

        Raw = raw_input().strip()
        current = 1
        freq = 0

        while True:
            freq += 1
            for x in range(L):
                current = ma[current][tr[Raw[x]]]
            if current == 1:
                break

        X = X % (freq * 100)
        if X == 0:
            X = freq * 100

        T = Raw * X
        N = len(T)

        def do():
            A, B, C = 1, 1, 1
            for x in range(N):
                A = ma[A][tr[T[x]]]
                if A == i:
                    break
            else:
                return False

            for y in range(x+1, N):
                B = ma[B][tr[T[y]]]
                if B == j:
                    break
            else:
                return False

            for z in range(y+1, N):
                C = ma[C][tr[T[z]]]

            return C == k

        result = do()
        print "Case #%d:" % C, "YES" if result else "NO"

main()
