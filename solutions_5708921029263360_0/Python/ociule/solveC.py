import itertools
from collections import defaultdict



def solve(j, p, s, k):

    #print(j, p, s, k)
    possibles = itertools.product(range(1, j+1), range(1, p+1), range(1, s+1))

    seen_combo_jp = defaultdict(lambda: 0)
    seen_combo_ps = defaultdict(lambda: 0)
    seen_combo_js = defaultdict(lambda: 0)
    out = []
    for o in possibles:
        j, p, s = o
        if seen_combo_jp[(j, p)] >= k:
            continue
        if seen_combo_ps[(p, s)] >= k:
            continue
        if seen_combo_js[(j, s)] >= k:
            continue
        out.append(o)

        # mark
        seen_combo_jp[(j, p)] += 1
        seen_combo_ps[(p, s)] += 1
        seen_combo_js[(j, s)] += 1

    return len(out), out


def main():
    n_tests = int(input())

    for ix_t in range(1, n_tests+1):
        jpsk = input().split()
        jpsk = (int(x) for x in jpsk)
        j, p, s, k = jpsk
        n, out = solve(j, p, s, k)
        print("Case #{}: {}".format(ix_t, n))
        for o in out:
            print(*o)

if __name__ == "__main__":
    main()
