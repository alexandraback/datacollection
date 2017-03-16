
import os
import sys
import glob
import subprocess
import random
import fileinput


next_line = 0
lines = [line.strip() for line in fileinput.input()]
def get_line():
    global next_line
    i = next_line
    next_line += 1
    return lines[i]


def mul(a, b):
    neg = 0
    if a[0] == '-':
        neg = 1 - neg
        a = a[1:]
    if b[0] == '-':
        neg = 1 - neg
        b = b[1:]

    if a == '1':
        ans = b
    elif b == '1':
        ans = a
    elif a == b:
        ans = '-1'
    else:
        ans = {'ij':'k', 'ik':'-j', 'jk':'i', 'ji':'-k', 'ki':'j', 'kj':'-i'}[a+b]

    if ans[0] == '-':
        neg = 1 - neg
        ans = ans[1:]

    return '-' + ans if neg else ans


L = None
X = None
s = None
prefix_values = None
full = None

def part1(a, l1):
    need = a
    if l1 > 0:
        need += 1
    if need > X:
        return ''

    ans = full[a]
    ans = mul(ans, prefix_values[l1])
    return ans

# ax = b
def find1x(a, b):
    if a[-1] == '1':
        return mul(a, b)
    return mul(mul('-1', a), b)

# axb = c
def find2x(a, b, c):
    if b[-1] == '1':
        return find1x(a, mul(b, c))
    return find1x(a, mul(mul('-1', c), b))

def postfix(l2):
    if l2 == 0:
        return '1'
    if l2 == L:
        return prefix_values[-1]

    return find1x(prefix_values[L - l2], prefix_values[-1])


def part2(a, l1, b, l2):
    if a + b + 2 <= X:
        return 'j'
        """
        ans = postfix(L - l1)
        n = X - (a + b + 2)
        ans = mul(ans, full[n%4])
        ans = mul(ans, prefix_values[L - l2])
        if ans == 'j':
            return 'j'
        """

    if a + b + 1 == X and l1 + l2 < L:
        return 'j'
        """
        if l1 == 0:
            return prefix_values[L - l2]
        if l2 == 0:
            return postfix(L - l1)
        return find2x(prefix_values[l1], postfix(l2), prefix_values[-1])
        """

    return ''


def part3(b, l2):
    need = b
    if l2 > 0:
        need += 1
    if need > X:
        return ''

    return mul(postfix(l2), full[b])


def calc():
    global L
    global X
    global s
    global prefix_values
    s = get_line().split(' ')

    L = int(s[0])
    X = int(s[1])
    s = get_line()

    prefix_values = ['1'] * (L + 1)
    for i in xrange(1, L + 1):
        prefix_values[i] = mul(prefix_values[i-1], s[i-1])

    global full
    full = [0] * 4
    full[0] = '1'
    full[1] = prefix_values[-1]
    full[2] = mul(full[1], prefix_values[-1])
    full[3] = mul(full[2], prefix_values[-1])


    if full[X%4] != '-1':
        return 'NO'

    #print prefix_values
    #print 3, prefix_values[3]
    #print 1017-13, prefix_values[1017-13]

    valid1 = []
    for a in xrange(4):
        for l1 in xrange(L):
            if part1(a, l1) == 'i':
                valid1.append((a, l1))
    #print len(valid1)

    valid2 = []
    for b in xrange(4):
        for l2 in xrange(L):
            if part3(b, l2) == 'k':
                valid2.append((b, l2))
    #print len(valid2)
    
    for a, l1 in valid1:
        for b, l2 in valid2:
            if part2(a, l1, b, l2) == 'j':
                #print a, l1, b, l2
                return 'YES'
    return 'NO'


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
