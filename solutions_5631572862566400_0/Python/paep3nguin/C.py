#! python3

from collections import Counter
from itertools import tee
def pairwise(iterable):
    "s -> (s0,s1), (s1,s2), (s2, s3), ..."
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)

def main():
    with open("C-small-attempt5.in") as in_file:
        with open("C-small-attempt5.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                N = int(in_file.readline().replace('\n', ''))
                prefs = [int(n) for n in in_file.readline().replace('\n', '').split(' ')]
                pref_count = Counter(prefs)
                prefs = {i + 1: n for i, n in enumerate(prefs)}
                reverse = {}
                for i, j in prefs.items():
                    l = reverse.get(j, [])
                    l.append(i)
                    reverse[j] = l

                unwanted = []

                for i in range(N):
                    if i+1 not in pref_count:
                        unwanted.append(i+1)

                best = N
                if unwanted:
                    best = 0
                    attempts = []
                    for k in unwanted:
                        attempt = []
                        curr = k
                        used = set()
                        used.add(k)
                        possible = True
                        while possible and len(used) < N:
                            nextk = prefs[curr]
                            if nextk not in used:
                                used.add(nextk)
                                attempt.append(curr)
                                curr = nextk
                            else:
                                possible = False
                                attempt.append(curr)
                        attempts.append(attempt)
                    if len(attempts) > 1:
                        for v, w in pairwise(attempts):
                            if v[-1] == w[-1]:
                                if len(set(v[:-1]) - set(w)) == len(v) - 1:
                                    t = len(v) + len(w) - 1
                                    if t > best:
                                        best = t
                            elif v[-2] == w[-1]:
                                if len(set(v[:-2]) - set(w)) == len(v) - 2:
                                    t = len(v) + len(w) - 2
                                    if t > best:
                                        best = t

                fout.write("Case #{0}: {1}\n".format(x + 1, best))

if __name__ == "__main__":
    main()
