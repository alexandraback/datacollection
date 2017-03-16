import sys
from collections import Counter, defaultdict
import networkx as nx

firstline = True
n = 1
in_count = 0
data = []
case = 1

longest_path = {}

def distwith(start, dic, inv_dic):
    out = [start]
    # build right
    while dic[out[-1]] not in out:
        out.append(dic[out[-1]])

    if dic[out[-1]] == out[0]:
        # cycle
        return len(out)
    elif len(out) > 1 and dic[out[-1]] == out[-2]:
        # build from center
        lval = str(dic[out[-1]]) + ' ' + str(dic[out[-2]])
        rval = str(dic[out[-2]]) + ' ' + str(dic[out[-1]])

        cur = max(len(out), longest_path[lval])
        longest_path[lval] = cur

        return cur + longest_path[rval] - 2
    else:
        return 0



for line in sys.stdin:
    if n == 1:
        pass
    else:
        line = line.strip()
        if (n % 2 == 1):
            def default_factory():
                    return 2
            longest_path = defaultdict(default_factory)
            vals = [int(i) for i in line.split(' ')]

            dic = {}
            for i, j in enumerate(vals):
                dic[i+1] = j
            starts = dic.keys()
            inv_dic = {}
            for k, v in dic.iteritems():
                inv_dic.setdefault(v, []).append(k)

            sizes = []
            for start in starts:
                sizes.append(distwith(start, dic, inv_dic))

            out = str(max(sizes))

            print 'Case #' + str(case) + ': ' + out
            case += 1
    n += 1
