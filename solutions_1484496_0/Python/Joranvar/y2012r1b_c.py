import sys

__author__ = 'joranvar'


def give_sets(sum, sums):
    sets = [s for s in sums if s[1] == sum]
    return ' '.join(map(str,sets[0][0])) + '\n' +' '.join(map(str,sets[1][0])) + '\n'

def solve(case):
    S = case[1:]

    sums = [({v}, v) for v in S]
    all_sums = set(S)

    n = 0
    for a in range(len(S)):
        print (len(sums))
        l = len(sums)-1
        for i in sums[n:l]:
            for v in S[a+1:]:
                if v > max(i[0]):
                    sums.append((i[0] | {v}, i[1] + v))
                    if i[1] + v in all_sums:
                        return give_sets(i[1] + v, sums)
                    all_sums.add(i[1] + v)
        n = l

    return 'Impossible\n'

if __name__ == "__main__":
    fi = open('c.in')

    T = int(fi.readline())
    cases = [list(map(int, l.split(' '))) for l in fi.readlines()]

    G = [s for s in map(solve, cases)]

    fo = open('c.out', 'w')
    fo.writelines(['Case #' + str(i) + ':\n' + l for i, l in enumerate(G,1)])

    fo.flush()
    fo.close()