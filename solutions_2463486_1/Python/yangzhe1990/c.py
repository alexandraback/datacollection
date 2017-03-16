#!/usr/bin/env python

import sys
import bisect

def create_multi_dim_array(dims, default):
    if len(dims) == 1:
        return [default] * dims[0]
    else:
        ret = []
        for i in xrange(dims[0]):
            ret.append(create_multi_dim_array(dims[1:], default))
        return ret

MAX_LEN = 25
LEN2 = 7

pal_list_by_len = create_multi_dim_array([2 * MAX_LEN + 3, 0], None)

def is_palindrome(s):
    l = len(s)
    k = l / 2
    #print "is_pal: %s %d %d" % (s, l, k)
    for i in xrange(k):
        if s[i] != s[l - i - 1]:
            return False
    return True

ten_power = map(lambda x: 10 ** x, xrange(2 * MAX_LEN + 3))

def reverse_int_to_str(x, n):
    l = []
    while x != 0:
        l.append(str(x % 10))
        x /= 10
    k = n - len(l)
    for i in xrange(k):
        l.append("0")
    return "".join(l)


def generate(n, prefix, suffix, prev_sqr_prefix_str, limit):
    log_prefix = "\t" * (n - 2)
    #print log_prefix + "generate %d %d %d %d %s" % (n, prefix, suffix, limit, prev_sqr_prefix_str)
    d = ten_power[n]
    new_d = ten_power[n + 1]
    new_suffix = suffix
    new_prefix = prefix * 10

    for i in xrange(3):
        sqr_suffix = new_suffix * new_suffix % new_d
        sqr_prefix_str = reverse_int_to_str(sqr_suffix, n + 1)

        actual_sqr_prefix_str = str(new_prefix * new_prefix / d)
        if (actual_sqr_prefix_str[:n] != prev_sqr_prefix_str):
            break
        #print log_prefix + "\t(%d, %d, %d, %s) %s" % (new_suffix, new_prefix, sqr_suffix, sqr_prefix_str, actual_sqr_prefix_str)

        # try prefix_i_suffix && prefix_i_i_suffix
        num = new_prefix * d + suffix
        #print "try %d" % num
        sqr = num * num
        if is_palindrome(str(sqr)):
            pal_list_by_len[2 * n + 1].append([num, sqr])

        num = new_prefix * new_d + new_suffix
        #print "try %d" % num
        sqr = num * num
        if is_palindrome(str(sqr)):
            pal_list_by_len[2 * n + 2].append([num, sqr])

        if n + 1 < limit and i < 2:
            generate(n + 1, new_prefix, new_suffix, actual_sqr_prefix_str, limit)

        new_suffix += d
        new_prefix += 1

for i in xrange(1, 10):
    if is_palindrome(str(i * i)):
        pal_list_by_len[1].append([i, i ** 2])
    if is_palindrome(str((i * 11) ** 2)):
        pal_list_by_len[2].append([i * 11, (i * 11) ** 2])

two_prefix_list = [10, 11, 12, 13, 20, 21, 22, 30, 31]

for i in two_prefix_list:
    d = i / 10 + i * 10
    if is_palindrome(str(d * d)):
        pal_list_by_len[3].append([d, d * d])
    d = i * 100 + i % 10 * 10 + i / 10
    if is_palindrome(str(d * d)):
        pal_list_by_len[4].append([d, d * d])

for i in two_prefix_list:
    suf = i % 10 * 10 + i / 10
    generate(2, i, suf, reverse_int_to_str(suf * suf % 100, 2), MAX_LEN - LEN2)

"""
for i in xrange(1, 2 * (MAX_LEN - LEN2)):
    for pair in pal_list_by_len[i]:
        pal_list.append(pair)
"""

pal_list = []

for suf_len in xrange(1, LEN2 + 1):
    prefix_list = map(lambda x: int("{0:b}".format(x)),
                      xrange(2 ** (suf_len - 1), 2 ** suf_len))
    prefix_list.append(2 * 10 ** (suf_len - 1))
    for prefix in prefix_list:
        suffix = int(reverse_int_to_str(prefix, suf_len))
        # |____|_______________|____|, suf_len, cl = 2(MAX_LEN - LEN2), suf_len
        cl1 = 2 * (MAX_LEN - LEN2)
        cl2 = cl1 - 1;
        d1 = ten_power[cl1 + suf_len]
        d2 = ten_power[cl2 + suf_len]
        num_pre1 = prefix * d1 + suffix
        num_pre2 = prefix * d2 + suffix

        num = num_pre1
        sqr = num * num
        if is_palindrome(str(sqr)):
            pal_list_by_len[cl1 + 2 * suf_len].append([num, sqr])

        num = num_pre2
        sqr = num * num
        if is_palindrome(str(sqr)):
            pal_list_by_len[cl2 + 2 * suf_len].append([num, sqr])

        for length in xrange(2, cl1 + 2, 2):
            for [a, b] in pal_list_by_len[length]:
                num = num_pre1 + a * ten_power[(cl1 - length) / 2 + suf_len]
                sqr = num * num
                if is_palindrome(str(sqr)):
                    pal_list_by_len[cl1 + 2 * suf_len].append([num, sqr])
        for length in xrange(1, cl2 + 2, 2):
            for [a, b] in pal_list_by_len[length]:
                num = num_pre2 + a * ten_power[(cl2 - length) / 2 + suf_len]
                sqr = num * num
                if is_palindrome(str(sqr)):
                    pal_list_by_len[cl2 + 2 * suf_len].append([num, sqr])

"""
# output
for length in xrange(1, MAX_LEN * 2 + 1):
    for [num, sqr] in pal_list_by_len[length]:
        print num, sqr
"""

pal_sqr_list = []
for length in xrange(1, MAX_LEN * 2 + 1):
    pal_sqr_list += map(lambda pair: pair[1], pal_list_by_len[length])

###############

case_cnt = int(sys.stdin.readline())
for i in xrange(1, case_cnt + 1):
    a_str, b_str = sys.stdin.readline().split()
    a, b = int(a_str), int(b_str)
    print "Case #%d: %d" % (i, 
                            bisect.bisect(pal_sqr_list, b)
                            - bisect.bisect_left(pal_sqr_list, a))
