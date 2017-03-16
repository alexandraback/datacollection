from collections import deque, defaultdict

def is_valid(comps):
    s = ''.join(''.join(c) for c in comps)
    deduped = ''
    for idx, ch in enumerate(s):
        if idx == 0 or s[idx - 1] != ch:
            deduped = deduped + ch

    return len(set(deduped)) == len(deduped)


    chars = defaultdict(int)
    for c in comps:
        charset = set([ch for sets in c for ch in sets])
        for ch in charset:
            if chars[ch] > 0:
                return False
            chars[ch] += 1

    return True

def count(comp):
    cnt = defaultdict(int)
    for s in comp:
        if s[0] == s[-1]:
            cnt[s[0]] += 1

    ret = 1
    for v in cnt.values():
        ret *= fact(v)

    return ret

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

if __name__ == '__main__':
    P = 1000000007
    for caseno in xrange(int(raw_input())):
        N = int(raw_input())
        sets = [s for s in raw_input().split()]


        comps = [deque([s]) for s in sets]
        while True:
            comps.sort(key=lambda c: len(set(''.join(c))))
            merge = None
            for i in xrange(len(comps) - 1):
                if merge:
                    break
                for j in xrange(i + 1, len(comps)):
                    if comps[i][0][0] == comps[j][-1][-1]:
                        merge = (j, i)
                        break
                    elif comps[i][-1][-1] == comps[j][0][0]:
                        merge = (i, j)
                        break
            if not merge:
                break

            comps[merge[0]].extend(comps[merge[1]])
            comps = comps[:merge[1]] + comps[merge[1] + 1:]

        if not is_valid(comps):
            sol = 0
        else:
            sol = fact(len(comps))
            for c in comps:
                sol = sol * count(c)
            sol = sol % P

        print 'Case #%d: %s' % (caseno + 1, sol)
