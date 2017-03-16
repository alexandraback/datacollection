from itertools import product

def goals(word, L):
    result = 0
    n = len(L)
    for i in range(len(word)):
        if word[i:i+n] == L:
            result += 1
    return result

def do_case(case_num, K, L, S):
    z = len(K) ** S
    max_x = 0
    sum_x = 0
    for word in product(K, repeat=S):
        word = ''.join(word)
        x = goals(word, L)
        max_x = max(max_x, x)
        sum_x += x
    result = max_x - sum_x * 1.0 / z
    print "Case #%d: %.8f" % (case_num, result)

t = int(raw_input())
for case_num in range(1, t + 1):
    _k, _l, S = map(int, raw_input().split())
    K = raw_input().strip()
    L = raw_input().strip()
    do_case(case_num, K, L, S)
