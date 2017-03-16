#!/usr/bin/python3

from codejam import CodeJam

def docase(f):
    n = int(f.readline())
    bff = [int(_)-1 for _ in f.readline().split()]
    bffs = set(bff)
    if len(bffs) == n:
        maxcycle = 0
        twos = 0
        while len(bffs) > 0:
            start = bffs.pop()
            curr = bff[start]
            bffs.remove(curr)
            cycle = 2
            while bff[curr] != start:
                curr = bff[curr]
                bffs.remove(curr)
                cycle += 1
            if cycle == 2:
                twos += 1
            maxcycle = max(maxcycle, cycle)
        return max(maxcycle, 2*twos)
    else:
        mutuals = []
        for student in range(n):
            if bff[student] > student and bff[bff[student]] == student:
                mutuals.extend([student, bff[student]])
        deadends = set(range(n)) - bffs
        maxcycle = 0
        mutualchains = {_:0 for _ in mutuals}
        alls = set(range(n)) - set(mutuals)
        for destudent in deadends:
            chain = [destudent]
            while True:
                b = bff[chain[-1]]
                if b in mutuals:
                    mutualchains[b] = max(mutualchains[b], len(chain))
                    for c in chain:
                        try:
                            alls.remove(c)
                        except KeyError:
                            pass
                    break
                if b in chain:
                    maxcycle = max(maxcycle, len(chain) - chain.index(b))
                    for c in chain:
                        try:
                            alls.remove(c)
                        except KeyError:
                            pass
                    break
                chain.append(b)
        while len(alls) > maxcycle and len(alls) > 0:
            start = alls.pop()
            curr = bff[start]
            cycle = 2
            while bff[curr] != start:
                curr = bff[curr]
                cycle += 1
            maxcycle = max(maxcycle, cycle)
        return max(maxcycle, sum(mutualchains.values()) + len(mutualchains))
        
cj = CodeJam(docase)

# After importing cj into an interactive terminal, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
