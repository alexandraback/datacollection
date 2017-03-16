from collections import defaultdict
from copy import copy


def read_data():
    n = int(raw_input())
    a_dict = {}
    b_dict = {}
    a_idx = 0
    b_idx = 0
    data = []
    for i in xrange(n):
        a, b = raw_input().split()
        if a not in a_dict:
            a_dict[a] = a_idx
            a_idx += 1
        if b not in b_dict:
            b_dict[b] = b_idx
            b_idx += 1
        data.append((a_dict[a], b_dict[b]))
    return data


def solve(case_no):
    topics = read_data()
    n = len(topics)
    distance = [-1] * (1 << n)
    distance[-1] = 0

    def dfs(mask, a_set, b_set):
        if distance[mask] != -1:
            return distance[mask]
        result = 0
        for i in xrange(n):
            if (mask & (1 << i)) == 0:
                a_set_copy = copy(a_set)
                b_set_copy = copy(b_set)
                a_set_copy.add(topics[i][0])
                b_set_copy.add(topics[i][1])
                if topics[i][0] in a_set and topics[i][1] in b_set:
                    result = max(result, dfs(mask | (1 << i), a_set_copy, b_set_copy) + 1)
                else:
                    result = max(result, dfs(mask | (1 << i), a_set_copy, b_set_copy))
        distance[mask] = result
        return result

    answer = dfs(0, set(), set())
    print "Case #%d: %d" % (case_no, answer)



def main():
    T = int(raw_input())
    for case_no in xrange(1, T + 1):
        solve(case_no)


main()
