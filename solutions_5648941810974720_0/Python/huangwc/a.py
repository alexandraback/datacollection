import sys

sys.stdin = open('A-small-attempt0.in', 'r')
sys.stdout = open('A-small.out', 'w')

for t in range(1, int(input()) + 1):

    D = {}
    C = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR',
         'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE', ]

    rem = 0
    success = False

    for c in input():
        D[c] = D.get(c, 0) + 1
        rem += 1

    S = []
    # print(S)
    # print(rem)
    # print(D)

    def dfs(n):

        global rem, success

        if success:
            return

        if n > 9:
            return

        s = C[n]

        status = 1
        for c in s:
            if D.get(c, 0) < 1:
                status = 0

        # print(n, rem)

        if status:

            for c in s:
                D[c] -= 1
                rem -= 1
            S.append(n)

            # print(n, rem)
            # print(S)
            # print(D)
            # print('')

            if rem == 0:
                success = True
                return

            dfs(n)

            dfs(n + 1)

            if success:
                return

            for c in s:
                D[c] += 1
                rem += 1
            del S[-1]

        dfs(n + 1)


    dfs(0)

    result = ''.join(map(str, S))

    print('Case #%s: %s' % (t, result))
