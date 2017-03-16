import sys, math

def slide(B, M):
    if M > 2 ** (B - 2):
        return 'IMPOSSIBLE'

    bitstr = bin(M)[2:]
    ans = [[0 for j in range(B)] for i in range(B)]

    for i in range(1, B):
        for j in range(i + 1, B):
            ans[i][j] = 1

    if len(bitstr) < B - 2:
        bitstr = '0' * (B - 2 - len(bitstr)) + bitstr

    if len(bitstr) == B - 1:
        for i in range(1, B):
            ans[0][i] = 1
    else:
        for i in range(1, B - 1):
            ans[0][i] = bitstr[i - 1]

    ans = '\n'.join([''.join(map(str, line)) for line in ans])
    return "POSSIBLE\n" + ans

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        BM = list(map(int, test.readline().strip().split()))
        print('Case #' + str(i + 1) + ': ' + str(slide(BM[0], BM[1])))
