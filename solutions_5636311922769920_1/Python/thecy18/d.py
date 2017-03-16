from sys import stdout


def solve(K, C, S):
    ret = []
    l = 0
    num = 0
    for i in range(K):
        num = num*K+i
        l += 1
        if l == C:
            l = 0
            ret.append(num+1)
            num = 0
    if l > 0:
        ret.append(num+1)
    if len(ret) > S:
        return 'IMPOSSIBLE'
    return ' '.join(str(r) for r in ret)

if __name__ == '__main__':
    namein = 'D-large.in'
    nameout = 'D-large.out'
    fin = open(namein, 'r')
    fout = open(nameout, 'w')
    # fout = stdout
    T = int(fin.readline())
    res = []
    for i in range(1, T+1):
        s = fin.readline()
        ss = s.split()
        K = int(ss[0])
        C = int(ss[1])
        S = int(ss[2])
        print('Case #{}: {}'.format(i, solve(K, C, S)), file=fout)
