import sys
import itertools
import time

sys.setrecursionlimit(200)


def checkKeysRaw(keys_needed, keys_total):
    keys_good = True
    for i in set(keys_needed):
        count_needed = keys_needed.count(i)
        count_total = keys_total.count(i)
        if count_needed > count_total:
            keys_good = False
            break
    if not keys_good:
        print "key bad"
    return keys_good


def checkKeys2(chests, keys):
    # Just try to find if it is possible to open all chests regardless of order
    # Open the chests with keys first, be greedy
    keys_needed = sorted(tuple([c[1] for c in chests]))
    chests_sorted = sorted(chests)
    keys_copy = keys[:]
    last_keys = []
    last_chests = []
    while len(chests_sorted) > 0:
        print keys_copy, chests_sorted, False
        i = 0
        while i < len(chests_sorted):
            total_keys = sum([len(c[2]) for c in chests_sorted])
            print total_keys
            c = chests_sorted[i]
            if c[1] in keys_copy and len(c[2]) > 0 and total_keys > 0:
                chests_sorted.pop(i)
                keys_copy.remove(c[1])
                keys_copy.extend(c[2])
            elif c[1] in keys_copy and len(c[2]) == 0 and total_keys == 0:
                chests_sorted.pop(i)
                keys_copy.remove(c[1])
            i += 1
        if tuple(keys_copy) == tuple(last_keys) and tuple(chests_sorted) == tuple(last_chests) and len(keys) > 0 and len(
                chests_sorted) > 0:
            print keys_copy, chests_sorted, False, False
            return False
        else:
            last_keys = keys_copy[:]
            last_chests = chests_sorted[:]
    print keys_copy, chests_sorted, True
    return True


def checkKeys(chests, keys):
    # Pre-check and see if we have enough keys...
    keys_needed = sorted([c[1] for c in chests])
    keys_total = sorted(keys[:] + list(itertools.chain(*[c[2] for c in chests])))
    # And we need the correct keys as well!
    return checkKeysRaw(keys_needed, keys_total)


def recursion(N, chests, keys, results):
    print chests
    print keys
    print results
    print
    if len(chests) == 0:
        if len(results) == N:
            # Right Answer
            return results
        else:
            # Wrong Answer
            return []
    elif not checkKeys2(chests, keys):
        return None
    else:
        first_chests = sorted(filter(lambda c: c[1] in keys, chests))
        i = 0
        removed = False
        while i < len(first_chests):
            c = first_chests[i]
            if len(keys) == 1 and not removed and len(chests) > 1:
                # remove chests with no keys in them
                first_chests = sorted(filter(lambda c: len(c[2]) > 0, first_chests))
                removed = True
                continue
            else:
                next_chests = chests.copy()
                next_chests.remove(c)
                next_keys = keys[:]
                next_keys.remove(c[1])
                next_keys.extend(c[2])
                next_results = results + [c]
                next_recursion = recursion(N, next_chests, next_keys, next_results)
                if next_recursion is not None:
                    return next_recursion
            i += 1
        return None


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        print case + 1
        K, N = map(int, fin.readline().strip().split(' '))
        keys = map(int, fin.readline().strip().split(' '))
        chests = set()
        for i in xrange(N):
            chest = map(int, fin.readline().strip().split(' '))
            chests.add((i + 1, chest[0], tuple(chest[2:])))

        keys_good = checkKeys(chests, keys)
        if not keys_good:
            print "key bad"
            answer = "IMPOSSIBLE"
        else:
            # DFS
            result = recursion(N, chests, keys, [])

            if result is None or len(result) == 0:
                print "no solution"
                answer = "IMPOSSIBLE"
            else:
                answer = ' '.join(map(lambda c: str(c[0]), result))
        print "Case #%d: " % (case + 1), answer
        print
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()


if __name__ == "__main__":
    # solve("D-tiny")
    solve("D-small-attempt2")
    # solve("D-large")