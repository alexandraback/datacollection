import sys
import itertools
from collections import Counter
import random

def solve(ws):
    fws, sws = Counter(w[0] for w in ws), Counter(w[1] for w in ws)
    originals = [set(),set()]
    potdupes = []
    x = False
    for w in ws:
        if fws[w[0]] == 1 or sws[w[1]] == 1:
            originals[0].add(w[0])
            originals[1].add(w[1])
            x = True
        else:
            potdupes.append(w)
    if not x:
        if len(ws) > 9:
            print(fws, sws, file=sys.stderr)
            print('Warning, will run loooong... ' + str(len(ws)), file=sys.stderr)
        bd = 0
        cnt = 0
        perm = list(range(len(ws)))
        while True: #for perm in itertools.permutations(range(len(ws))):
            random.shuffle(perm)
            og2 = [set(),set()]
            dups = 0
            for i in perm:
                w = ws[i]
                if ( w[0] in og2[0] and w[1] in og2[1]):
                    dups += 1
                else:
                    og2[0].add(w[0])
                    og2[1].add(w[1])
            bd = max(bd, dups)
            cnt += 1
            if cnt > 1e5:
                print('Aborting, hope the correct answer has been found...', file=sys.stderr)
                break
        return bd

    dupes = 0
    potdupes2 = []
    for w in potdupes:
        if w[0] in originals[0] and w[1] in originals[1]:
            dupes += 1
        else:
            potdupes2.append(w)

    bd = 0
    if potdupes2:
        bd = solve(potdupes2)

    return dupes + bd




if __name__ == '__main__':
    lines = sys.stdin.readlines()
    T = int(lines[0])
    i = 1
    for t in range(T):
        n = int(lines[i])
        topics = [tuple(x.split()) for x in lines[i+1:i+n+1]]
        print('Case #{}: {}'.format(t+1, solve(topics)))
        i += n+1

