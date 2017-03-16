# source code for GCJ2013 round 1B
# by Pengyu CHEN(cpy.prefers.you@gmail.com)
# COPYLEFT, ALL WRONGS RESERVED.

import sys

MAX = 99999

def calce(S, i, w):
    frste = MAX
    laste = -MAX
    ecnt = 0
    for j in range(len(w)):
        if S[i + j] != w[j]:
            if j - laste < 5:
                return MAX, 0, 0
            else:
                ecnt += 1
                if frste == MAX:
                    frste = j
                laste = j
    return ecnt, frste, max(0, 5 - (len(w) - laste))

def main():
    f = open("C_dict.txt", "r")
    d = list(map(lambda x: x.replace("\n", ""), f.readlines()))
    f.close()

    T = int(input())
    for t in range(T):
        sys.stderr.write("log: Case %d/%d\n" %(t + 1, T))
        S = raw_input()
        prec = [[(MAX, MAX, -MAX) for i in range(len(d))] for j in range(len(S))]
        for i in range(len(S)):
            for w in range(len(d)):
                if i + len(d[w]) <= len(S):
                    prec[i][w] = calce(S, i, d[w])

        ans = 0
        mine = [[0] + [MAX for i in range(len(S))] + [0] * 5] * 5
        for i in range(len(S)):
            for w in range(len(d)):
                if i + len(d[w]) <= len(S):
                    e, fe, le = prec[i][w]
                    for j in range(5):
                        if j <= fe:
                            if mine[j][i] + e < mine[le][i + len(d[w])]:
                                mine[le][i + len(d[w])] = mine[j][i] + e
        
        ans = min(mine[x][len(S)] for x in range(5))

        print("Case #%d: %s" %(t + 1, ans))
    pass

if __name__ == "__main__":
    main()
