import gcj, sys

def getBinPair(A, B):
    A = bin(A).replace('0b', '')
    B = bin(B).replace('0b', '')
    la, lb = len(A), len(B)

    if la > lb:
        B = "0"*(la-lb) + B
    else:
        A = '0' * (len(B) - len(A)) + A

    return A, B

def andBin(a, b):
    ans = ''

    for idx in range(len(a)):
        aa = int(a[idx])
        bb = int(b[idx])

        if aa and bb: ans = ans + '1'
        else: ans = ans + '0'

    return int(ans, 2)

def solve(A, B, K):
    result = 0
    pairs = []

    for a in range(0, A):
        for b in range(0, B):
            aa, bb = getBinPair(a, b)
            if andBin(aa, bb) < K:
                result += 1
                pairs.append((a, b))

    return result

def main():
    IN = gcj.FileWrapper(open(sys.argv[1]))
    N = IN.getInt()

    for n in range(N):
        A, B, K = IN.getInts()
        gcj.printCase(solve(A, B, K))
        

if __name__ == '__main__':
    main()
