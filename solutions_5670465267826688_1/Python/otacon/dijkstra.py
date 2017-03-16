#!/usr/bin/python3.4

import sys
import math

ht = {
        '1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k', '-': '-', 'I': 'I', 'J': 'J', 'K': 'K'},
        'i': {'1': 'i', 'i': '-', 'j': 'k', 'k': 'J', '-': 'I', 'I': '1', 'J': 'K', 'K': 'j'},
        'j': {'1': 'j', 'i': 'K', 'j': '-', 'k': 'i', '-': 'J', 'I': 'k', 'J': '1', 'K': 'I'},
        'k': {'1': 'k', 'i': 'j', 'j': 'I', 'k': '-', '-': 'K', 'I': 'J', 'J': 'i', 'K': '1'},
        '-': {'1': '-', 'i': 'I', 'j': 'J', 'k': 'K', '-': '1', 'I': 'i', 'J': 'j', 'K': 'k'},
        'I': {'1': 'I', 'i': '1', 'j': 'K', 'k': 'j', '-': 'i', 'I': '-', 'J': 'k', 'K': 'J'},
        'J': {'1': 'J', 'i': 'k', 'j': '1', 'k': 'I', '-': 'j', 'I': 'K', 'J': '-', 'K': 'i'},
        'K': {'1': 'K', 'i': 'J', 'j': 'i', 'k': '1', '-': 'k', 'I': 'j', 'J': 'I', 'K': '-'}}

cache = {}

def eval(s):
    if len(s) == 0:
        return '1'

    if len(s) == 1:
        return s

    cached = cache.get(s, None)
    if  cached != None:
        return cached

    cur = s[0]
    for c in s[1:]:
        cur = ht[cur][c]

    cache[s] = cur
    return cur

def find_i(x, s):
    l = len(s)
    cur = s[0]

    pos = 1

    while pos < l * min(x, 64):
        if cur == 'i':
            return pos
        c = s[pos % l]
        cur = ht[cur][c]

        pos+=1

    return None

def find_k(x, s):
    l = len(s)
    cur = s[-1]

    pos = x * l - 1
    pos2 = pos - l * min(x, 16*16)
    while pos > 1 and pos > pos2:
        if cur == 'k':
            return pos
        pos -= 1
        c = s[pos % l]
        cur = ht[c][cur]

    return None

cache_2 = {}
def eval_blocks(s, nb):
    if nb <= 0:
        return '1'
    if nb == 1:
        return eval(s)

    cached = cache_2.get(str(nb)+ ' - ' + s, None)
    if cached != None:
        return cached

    c = eval_blocks(s, nb//2)
    result = ht[c][c]
    if nb % 2 == 1:
        result = ht[result][eval(s)]

    cache_2[str(nb) + ' - ' + s] = result
    return result

def eval_pp(x, s, p1, p2):
    l = len(s)

    cur = s[p1%l]

    p1+=1
    while p1 % l != 0:
        if p1 == p2:
            return cur
        c = s[p1 % l]
        cur = ht[cur][c]
        p1+=1

    blocks_p2 = (p2 - p1) // l

    c = eval_blocks(s, blocks_p2)
    #print('eval_blocks(', s, blocks_p2, ') = ', c)

    cur = ht[cur][c]

    p1 += blocks_p2 * l

    while True:
        if p1 >= p2:
            return cur
        c = s[p1 % l]
        cur = ht[cur][c]
        p1+=1

    return cur

def solve(x, s):
    if x * len(s) <3:
        return False

    pi = find_i(x, s)
    pk = find_k(x, s)

    if pi == None or pk == None:
        return False

    if pi >= pk:
        return False

    last = eval_pp(x, s, pi, pk)
    if last == 'j':
        return True

    return False

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        l = get_line().split()
        L, X = [int(i) for i in l]

        s = get_line()
        v = solve(X, s)

        if v == True:
            ret = 'YES'
        else:
            ret = 'NO'

        print('Case #%d: %s' % (case_id, ret), file = o)

def get_line():
    return f.readline().strip()

def open_files():
    if len(sys.argv) == 1:
        f = sys.stdin
        o = sys.stdout

    if len(sys.argv) == 2:
        f = open(sys.argv[1], 'r')
        o = sys.stdout

    if len(sys.argv) == 3:
        f = open(sys.argv[1], 'r')
        o = open(sys.argv[2], 'w')

    return (f, o)

if __name__ == "__main__":
    (f, o) = open_files()
    main()

