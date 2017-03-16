#!/usr/bin/python
import itertools

def match(s,t):
    for i in range(len(s)):
        if s[i] == '?':
            continue
        if s[i] != t[i]:
            return False
    return True

T = input()
for test in range(T):
    c,j = raw_input().split()
    nums = ["".join(i) for i in itertools.product("0123456789",repeat=len(c))]

    c_nums = filter(lambda x: match(c,x), nums)
    j_nums = filter(lambda x: match(j,x), nums)

    #print c_nums
    #print j_nums

    mindiff = float("inf")
    c_ans = ""
    j_ans = ""
    for c in c_nums:
        for j in j_nums:
            c_int = int(c)
            j_int = int(j)
            diff = abs(c_int - j_int)
        
            if diff < mindiff:
                mindiff = diff
                c_ans = c
                j_ans = j
            elif diff == mindiff:
                if c_int < int(c_ans):
                    c_ans = c
                    j_ans = j
                elif c_int == int(c_ans):
                    if j_int < int(j_ans):
                        c_ans = c
                        j_ans = j

    print "Case #{}: {} {}".format(test+1, c_ans, j_ans)
