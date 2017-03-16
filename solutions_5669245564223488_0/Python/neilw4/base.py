#!/usr/bin/python
import sys
from math import factorial
from copy import deepcopy

def memo(f):
    cache = {}

    def memf(*x):
        xs = str(x)
        if not xs in cache:
            cache[xs] = f(*x)
        return cache[xs]
    return memf


@memo
def got(c, cs):
    # print "GOT", c, cs
    valid = list()
    for ch in c:
        for cc in cs:
            if ch in cc:
                # print "conflict on char " + ch, c, "<->", cc
                if ch == cc[0] and ch == c[-1]:
                    valid.append(cc)
                else:
                    # print "no valid comb"
                    return 0

    if len(cs) == 1:
        # print "base case", cs[0]
        return 1

    if len(valid) > 0:
        # print "found valid:", valid
        if len(valid) == 1:
            v = valid[0]
            cs.remove(v)
            # print "one option recurse on", v, cs
            count = got(v, cs)
            # print "end recurse on", v, cs
            cs.append(v)
            return count
        cs = valid


    count = 0
    s = deepcopy(cs)

    # print "ITERATE", s, len(s)
    for cc in s:
        # print cc, "<=", s, len(s)
        cs.remove(cc)
        # print "recurse on", cc, cs
        count += got(cc, cs)
        # print "end recurse on", cc, cs
        cs.append(cc)
    # print "count on", c, cs, "is", count
    return count



def solve(l):
    cs = list();# = l.split(' ')

    lst = None
    for c in l.split(' '):
        s = ""
        for ch in c:
            if ch != lst:
                s += ch
            lst = ch
        cs.append(s)
        lst = None


    count = 0
    for c in cs:
        cs.remove(c)
        # print "try", c, cs
        count += got(c, cs)
        cs.append(c)

    return count % 1000000007;



# @memo
# def got(c, cs):
#     for ch in c[1:-1]:
#         for cc in cs:
#             if ch in cc[1:-1]:
#                 return

#     if len(cs) == 1:
#         return 1

#     has = list()
#     use = list()
#     for cc in cs:
#         if cc[-1] == c[-1]:
#             if cc[-1] == cc[0]:
#                 use.append(cc)
#             else:
#                 has.append(cc)
#     count = 0

#     if len(use) == 0:
#         if len(has) == 1:
#             cs.remove(list(has)[0])
#         for cc in cs:
#             cs.remove(cc)
#             count += got(cc, cs)
#             cs.append(cc)
#         if len(has) == 1:
#             cs.append(has[0])

#     else:
#         if len(has) > 1:
#             return 0
#         else:
#             perms = factorial(len(use))
#             if len(has) == 1:
#                 cs.remove(has[0])

#                 for cc in cs:
#                     cs.remove(cc)
#                     count += got(cc, cs)
#                     cs.append(cc)

#             if len(has) == 1:
#                 cs.append(has[0])


#     return count


# def solve(l):
#     cs = l.split(' ')

#     count = 0
#     for c in cs:
#         cs.remove(c)
#         count += got(c, cs)
#         cs.append(c)

#     return count % 1000000007;



#needs an input file
infname = sys.argv[1]
inf = open(infname)
#assumes infname ends with .in
outfname = infname[:-3] + ".out"
#output file can be specified separately
if len(sys.argv) > 2:
    outfname = sys.argv[2]
outf = open(outfname, "w")
case = 1
#ignore 1st line
inf.readline()
while True:
    inf.readline()
    line = inf.readline()
    if line == '':
        break
    sol = "Case #" + str(case) + ": " + str(solve(line.strip()))
    print sol
    outf.write(sol + "\n")
    case += 1
