#!/USSR/bin/env python3

import numpy as np

def mypower(a, n):
    ret = a.copy()
    total = ret[0][a.shape[0]-1]
    for i in range(n):
        ret = ret.dot(a)
        total += ret[0][a.shape[0]-1]
    return ret, total

T = int(input())
for t in range(1, T+1):
    ans = ''

    B, M = map(int, raw_input().split())
    # a = np.array([[0,1,0,0,1],
    #               [0,0,1,1,0],
    #               [0,0,0,0,1],
    #               [0,0,1,0,1],
    #               [0,0,0,0,0]])
    # print(ans_format)
    # print(mypower(a, 4))
    if M >= (B * (B-1) / 2):
        ans = "IMPOSSIBLE"
        print("Case #{}: {}".format(t, ans))
        continue
    ans_format = np.zeros((B, B), dtype=np.int)
    ans_format[0][B-1] = 1
    for bits in range(1, 2 ** ((B-1) * (B-1))):
        # print("bits ========", bits)
        # if bin(bits).count('1') != M:
        #     continue
        l = np.zeros((B, B), dtype=int)
        for c, b in enumerate(bin(bits)[2:][::-1]):
            if b=='1':
                l[(c/(B-1))][1+c%(B-1)] = 1
        flag = False

        for i in range(B):
            if l[i][i] == 1:
                flag = True
                break
        if flag is True:
            continue

        # print(l)
        mat, tmp = mypower(l, M)
        if not np.array_equal(mat, np.zeros((B,B))):
            continue
        if tmp == M:
            ans = "POSSIBLE"
            break
    if ans == "POSSIBLE":
        print("Case #{}: {}".format(t, ans))
        for h in l:
            print("".join(str(h)[1:-1].split()))
    else:
        ans = "IMPOSSIBLE"
        print("Case #{}: {}".format(t, ans))
