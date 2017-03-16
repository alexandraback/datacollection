#!/usr/bin/python
import sys

rsum_m = {}


def sum_lists(lists):
    s = [0 for i in xrange(max([len(i) for i in lists]))]
    for i in lists:
        for j in xrange(len(i)):
            s[j] += i[j]
    return s


def find_treasure(keychain, chests, r=[]):
    if len(r) == len(chests):
        return r

    def sum_chests(r):
        r_string = " ".join([str(i) for i in r])
        if r_string not in rsum_m:
            if len(r) == 1:
                return chests[r[0]][2]
            elif len(r) > 2:
                r_sum = sum_lists([sum_chests(r[:-2]), chests[r[-1]][2]])
            else:
                r_sum = sum_lists([chests[r[i]][2] for i in xrange(len(r))])
            rsum_m[r_string] = r_sum
            return r_sum
        else:
            return rsum_m[r_string]

    def recourse(i):
        ch = chests[:]
        ch[i][3] = True
        rr = r + [i]
        kc = sum_lists([sum_chests(rr), keychain])
        kc[ch[i][0]] -= 1
        return find_treasure(kc, ch, rr)

    tried_keys = set()
    for i, c in enumerate(chests):
        if c[3] or keychain[c[0]] == 0:  # Already opened or no keys
            continue
        if len(tried_keys) == 0:
            nr = recourse(i)
            if len(nr) > 0:
                return nr
        else:
            new_keys = list[set(c[1]) - tried_keys]
            if len(new_keys) > 0:
                recourse(i)
                if len(nr) > 0:
                    return nr
    return []


if __name__ == "__main__":
    if len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            s = f.read()
    else:
        with open("/home/paulo/Downloads/D-small-attempt0.in") as f:
            s = f.read()

    line, s = 1, s.strip().split("\n")
    while line < len(s):
        for t in xrange(1, 1 + int(s[0])):
            K, N = [int(i) for i in s[line].split()]
            line += 1
            keys, chests = [int(i) for i in s[line].split()], []
            keychain = [len([k for k in keys if k == i]) for i in xrange(201)]
            line += 1
            for n in xrange(N):
                c = [int(i) for i in s[line].split()]
                line += 1
                chests.append([int(c[0]), c[2:],
                    [len([k for k in c[2:] if k == i]) for i in xrange(201)],
                    False])
            treasure = find_treasure(keychain, chests)
            if len(treasure) == 0:
                print "Case #%d: IMPOSSIBLE" % t
            else:
                print "Case #%d: %s" % (t,
                    " ".join([str(i) for i in treasure]))
