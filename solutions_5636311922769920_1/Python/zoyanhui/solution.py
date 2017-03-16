import math


def print_case_result(case_num, result):
    print "Case #" + str(case_num) +": ",
    if type(result) is str:
        print result
    else:
        for v in result:
            print v,
        print

def calc_next(cur, i, cover_set, K):
    if i < len(cover_set) - 1:
        new = (cur - 1) * K + cover_set[i+1]
    else:
        if cover_set[i] == 1:
            new = cover_set[i]
        else:
            new = (cover_set[i] - 1) * K + cover_set[i]
    return new

def calc_viewset(K, C, S):
    all_set = range(1, K + 1)
    if C == 1:
        return all_set if S >= len(all_set) else "IMPOSSIBLE"
    elif K == 1:
        return all_set
    if math.ceil((K + 0.0) / C ) > S:
        return "IMPOSSIBLE"
    view_set = []
    i = 1
    while i <= K:
        sp = all_set[i-1: i + C - 1]
        cur = sp[0]
        if len(sp) == 1:
            if sp[0] == 1:
                cur = 1
            else:
                cur = (cur - 2) * K + cur
        for cover_v in sp[1:]:
            cur = (cur - 1) * K + cover_v
        view_set.append(cur)
        i+= C
    return view_set


if __name__ == '__main__':
    testcase_num = int(raw_input())
    for case_num in range(1, testcase_num+1):
        K, C, S = map(int, raw_input().strip().split())
        view_set = calc_viewset(K, C, S)
        print_case_result(case_num, view_set)

        

