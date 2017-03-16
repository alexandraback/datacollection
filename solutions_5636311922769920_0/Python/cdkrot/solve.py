#!/usr/bin/python3

def gen(k, lst):
    res, pw = 0, 1
    for i in range(len(lst)):
        res += pw * lst[i]
        pw *= k
    return res
        

def solve(k, c, s):
    min_ans = (k // c) + (k % c != 0)
    if min_ans > s:
        return "IMPOSSIBLE"

    answers = []
    p_cur = 0
    while p_cur != k:
        lst = []
        while len(lst) < c and p_cur != k:
            lst.append(p_cur)
            p_cur += 1
        while len(lst) < c:
            lst.append(0)
        answers.append(gen(k, lst) + 1)
    return " ".join(map(str, answers))

def main():
    t = int(input())
    for i in range(1, t + 1):
        k, c, s = map(int, input().split())
        print("Case #{}: {}".format(i, solve(k, c, s)))

main()
