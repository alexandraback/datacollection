__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        D = int(get_line())
        lst = formatIntegerList(get_line())
        yield (i+1, (D, lst))


def handle_case(case):
    D, lst = case
    assert len(lst) == D
    if len(lst) == 0:
        return 0
    dic = lst_to_dictionary(lst)
    m = max(dic)
    result = m
    for t in xrange(2, m):
        special_minutes = 0
        for v in dic:
            special_minutes += (v/t + (v % t > 0) - 1) * dic[v]
        result = min(result, t + special_minutes)
    return result

def lst_to_dictionary(lst):
    dic = dict()
    for x in lst:
        if x in dic:
            dic[x] += 1
        else:
            dic[x] = 1
    return dic


def backtrack0(dic, depth=9):
    if max(dic) == 1:
        return 1
    if depth == 0:
        return 9
    result = backtrack0(minute(dic), depth - 1) + 1
    for x in [max(dic)]:
        for c in xrange(1, x/2+1):
            new_dic = dict(dic)
            new_dic[x] -= 1
            if new_dic[x] == 0:
                new_dic.pop(x)
            for v in [c, x-c]:
                if v not in new_dic:
                    new_dic[v] = 0
            new_dic[c] += 1
            new_dic[x - c] += 1
            result = min(result, backtrack0(new_dic, depth - 1) + 1)
    return result


def backtrack(dic):
    if max(dic) == 1:
        return 1
    try1 = minute(dic)
    try2, delta = try_improve(dic)
    r1 = backtrack(try1) + 1
    r2 = backtrack(try2) + delta
    return min(r1, r2)


def minute(dic):
    new_dic = dict()
    for x in dic:
        if x > 1:
            new_dic[x-1] = dic[x]
    return new_dic

def try_improve(dic):
    m = max(dic)
    assert m > 1
    new_dic = dict(dic)
    new_dic.pop(m)
    if m/2 not in new_dic:
        new_dic[m/2] = dic[m]
    else:
        new_dic[m/2] += dic[m]
    if m/2 + m % 2 not in new_dic:
        new_dic[m/2 + m % 2] = dic[m]
    else:
        new_dic[m/2 + m % 2] += dic[m]
    return new_dic, dic[m]


def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()