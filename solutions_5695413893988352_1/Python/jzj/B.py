from copy import copy


def to_max(l):
    for i in xrange(len(l)):
        if l[i] == '?':
            l[i] = '9'


def to_min(l):
    for i in xrange(len(l)):
        if l[i] == '?':
            l[i] = '0'


def judge_has_a_less(first_list, second_list, rev):
    first_list = copy(first_list)
    second_list = copy(second_list)
    to_max(first_list)
    to_min(second_list)
    first_num = int(''.join(first_list))
    second_num = int(''.join(second_list))
    if first_num > second_num:
        raise Exception()
    if rev:
        return second_num - first_num, second_num, first_num
    else:
        return second_num - first_num, first_num, second_num


def real_solve(first_str, second_str, rev):
    first_list = list(first_str)
    second_list = list(second_str)
    n = len(first_str)
    res = [(10 ** 50, 0, 0)]

    def dfs(i):
        if i == n:
            first_num = int(''.join(first_list))
            second_num = int(''.join(second_list))
            if first_num > second_num:
                raise Exception()
            if rev:
                res[0] = min(res[0], (second_num - first_num, second_num, first_num))
            else:
                res[0] = min(res[0], (second_num - first_num, first_num, second_num))
            return
        if first_list[i] == '?' and second_list[i] == '?':
            first_list[i] = '0'
            second_list[i] = '0'
            dfs(i + 1)
            second_list[i] = '1'
            res[0] = min(res[0], judge_has_a_less(first_list, second_list, rev))
            first_list[i] = '?'
            second_list[i] = '?'
        elif first_list[i] == '?':
            first_list[i] = second_list[i]
            dfs(i + 1)
            if second_list[i] != '0':
                first_list[i] = str(int(second_list[i]) - 1)
                res[0] = min(res[0], judge_has_a_less(first_list, second_list, rev))
            first_list[i] = '?'
        elif second_list[i] == '?':
            second_list[i] = first_list[i]
            dfs(i + 1)
            if first_list[i] != '9':
                second_list[i] = str(int(first_list[i]) + 1)
                res[0] = min(res[0], judge_has_a_less(first_list, second_list, rev))
            second_list[i] = '?'
        else:
            if first_list[i] < second_list[i]:
                res[0] = min(res[0], judge_has_a_less(first_list, second_list, rev))
            elif first_list[i] > second_list[i]:
                return
            else:
                dfs(i + 1)

    dfs(0)
    return res[0]


def solve(case_no):
    first_str, second_str = raw_input().split()
    ans = min(real_solve(first_str, second_str, False), real_solve(second_str, first_str, True))
    s1 = str(ans[1])
    s1 = '0' * (len(first_str) - len(s1)) + s1
    s2 = str(ans[2])
    s2 = '0' * (len(first_str) - len(s2)) + s2
    print "Case #%d: %s %s" % (case_no, s1, s2)


def main():
    T = int(raw_input())
    for case_no in xrange(1, T + 1):
        solve(case_no)


main()
