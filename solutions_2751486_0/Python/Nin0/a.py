#!/usr/bin/python3

import sys
N_MAX = 10**6

T = int(sys.stdin.readline())
caseNum = 0

vowels = "eaiou"

def solve(s, n):
    global wovels
    seq = [0]
    cnt = 0
    s_len = 0 # length of s
    for c in s:
        s_len += 1
        if c not in vowels:
            cnt += 1
        else:
            if cnt >= n:
                seq.extend([cnt, 1])
            else:
                seq[-1] += cnt+1
            cnt = 0
    if cnt >= n:
        seq.extend([cnt, 0])
    else:
        seq[-1] += cnt
    # print("\n")
    # print("n =", n)
    # print(seq)
    ans = 0
    left_part = 0
    for i in range(1, len(seq), 2):
        left_part += seq[i-1] + seq[i]
        right_part = s_len - left_part
        ans += (seq[i-1]+1+(0 if i-2 < 0 else n-1))*(right_part+1+seq[i]-n)
        # print("Prispevek: ", (seq[i-1]+1)*(right_part+1+seq[i]-n))
        a, b = right_part + 1, right_part + seq[i] - n
        if a <= b:
            ans += b*(b+1) // 2 - a*(a-1) // 2
            # print("Prispevek a-b: ", b*(b+1) // 2 - a*(a-1) // 2)
    return ans

while caseNum < T:
    caseNum += 1
    s, n = sys.stdin.readline().strip().split(' ')
    n = int(n)
    print("Case #{0}: {1}".format(caseNum, solve(s, n)))
