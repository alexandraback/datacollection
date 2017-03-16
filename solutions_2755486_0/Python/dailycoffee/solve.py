from itertools import groupby

def solve(tribes):
    attacks = []
    for t in tribes:
        D, N, W, E, S, DD, DP, DS = t
        for i in range(N):
            d = D + DD * i
            w = W + DP * i
            e = E + DP * i
            s = S + DS * i
            attacks.append((d, w, e, s))
    attacks = sorted(attacks)
    ret = 0
    days = []
    for k, g in groupby(attacks, key=lambda x: x[0]):
        days.append(list(g))
    wall = {}
    for day in days:
        for a in day:
            _d, w, e, s = a
            for i in range(w, e):
                h = wall.get(i, 0)
                if h < s:
                    ret += 1
                    break
        for a in day:
            _d, w, e, s = a
            for i in range(w, e):
                wall[i] = max(wall.get(i, 0), s)
    return ret

def line(f):
    return map(int, f.readline().split())

def main(f):
    (T,) = line(f)
    for i in range(T):
        (N,) = line(f)
        tribes = []
        for j in range(N):
            rec = line(f)
            tribes.append(rec)
        assert len(tribes) == N
        print('Case #{}: {}'.format(i + 1, solve(tribes)))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
    #with open('sample.in') as f:
        #main(f)
