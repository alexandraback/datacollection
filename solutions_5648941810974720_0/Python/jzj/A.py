from collections import defaultdict


def getcount(s):
    res = defaultdict(lambda: 0)
    for c in s:
        res[c] += 1
    return res

number_table = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
dict_table = [getcount(s) for s in number_table]
# 0: Z
# 2: W
# 6: X
# 8: G
order = [0, 2, 6, 8, 4, 5, 1, 3, 7, 9]

def solve(case_no):
    raw_s = raw_input()
    s = getcount(raw_s)
    count = [0] * 10
    def dfs(pos, remain):
        if pos == 10:
            if remain == 0:
                return True
            return False
        max_num = 10000000
        cur_digit = order[pos]
        for k, v in dict_table[cur_digit].iteritems():
            max_num = min(max_num, s[k] // v)
        for num in xrange(max_num, -1, -1):
            count[cur_digit] = num
            for k, v in dict_table[cur_digit].iteritems(): s[k] -= num * v
            if dfs(pos + 1, remain - num * len(number_table[cur_digit])):
                return True
            for k, v in dict_table[cur_digit].iteritems(): s[k] += num * v
        return False
    dfs(0, len(raw_s))
    print "Case #%d: %s" % (case_no, ''.join(t * str(i) for i, t in enumerate(count)))



T = int(raw_input())
for case_no in xrange(1, T + 1):
    solve(case_no)
