# This is an instance of the longest common subsequence
#

def len_lcs(seq1, seq2, c = 0):
    if not seq1 or not seq2: return c

    n1, t1 = seq1[0]
    n2, t2 = seq2[0]
    rest1 = seq1[1:]
    rest2 = seq2[1:]
    if t1 == t2:
        if n1 == n2:
            return len_lcs(rest1, rest2, c+n1)
        if n1 < n2:
            return len_lcs(rest1, [(n2-n1,t1)]+rest2, c+n1)
        if n1 > n2:
            return len_lcs([(n1-n2,t1)]+rest1, rest2, c+n2)
    else:
        return max(len_lcs(seq1, rest2, c), len_lcs(rest1, seq2, c))

def parse_line(l):
    elems = iter(l.split())
    lst = []
    while True:
        try:
            n = int(next(elems))
            type = int(next(elems))
            lst.append((n, type))
        except StopIteration:
            break
    return lst

def parse(f):
    lines = f.xreadlines()
    next(lines)
    while True:
        try:
            next(lines)
            line1 = parse_line(next(lines))
            line2 = parse_line(next(lines))
            yield (line1, line2)
        except StopIteration:
            break

import sys
i = 1
for line1, line2 in parse(open(sys.argv[1])):
    print "Case #{}: {}".format(i, len_lcs(line1, line2))
    i+=1
