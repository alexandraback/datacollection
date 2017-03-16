#!/usr/bin/env python
import sys
import csv

def intreader(path):
    for line in csv.reader(file(path), delimiter=' '):
        yield map(int, line)

def solve(initial_keys, chests):
    memo = {}
    openmemo = {}
    ktypemap = {}
    for ii, (ktype, _) in enumerate(chests):
        if ktype not in ktypemap:
            ktypemap[ktype] = set()
        ktypemap[ktype].add(ii)

    def depthsearch(keys, opened):
        if len(opened) == len(chests):
            return opened

        ukeys = set(keys)

        omemokey = tuple(sorted(ukeys))
        if omemokey in openmemo:
            openable = openmemo[omemokey]
        else:
            openable = set()
            for k in ukeys:
                openable.update(ktypemap.get(k, set()))
            openmemo[omemokey] = openable
        openable -= set(opened)

        #for k in ukeys:
        #    if k not in ktypemap:
        #        continue
        #    openable = ktypemap[k] - set(opened)
        for o in sorted(openable):
            # Key removing used key and adding keys in
            # opened chest.
            rkeys = list(keys)
            rkeys.remove(chests[o][0])
            rkeys.extend(chests[o][1])

            nopened = opened + [o]
            memo_key = (tuple(sorted(rkeys)), tuple(sorted(nopened)))

            if memo_key in memo:
                result = memo[memo_key]
            else:
                result = depthsearch(rkeys, opened + [o])
                memo[memo_key] = result
            if result:
                return result
        return None

    result = depthsearch(initial_keys, [])
    if result:
        return ' '.join(str(x + 1) for x in result)
    else:
        return 'IMPOSSIBLE'

def main():
    reader = intreader(sys.argv[1])
    T = reader.next()[0]
    for ii in range(T):
        K, N = reader.next()
        keys = reader.next()
        chests = []
        for kk in range(N):
            record = reader.next()
            chests.append((record[0], record[2:]))
        print 'Case #{}: {}'.format(ii+1, solve(keys, chests))




if __name__ == '__main__':
    main()
