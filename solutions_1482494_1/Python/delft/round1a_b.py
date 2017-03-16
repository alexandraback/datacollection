# http://code.google.com/codejam/contest/dashboard?c=975485#

import sys

def parse(filename):
    f = open(filename)
    T = int(f.readline())
    for i in range(T):
        line = f.readline().strip()
        terms = line.split()
        N = int(terms[0])
        levels = []
        for j in range(N):
            line = f.readline().strip()
            levels.append([int(a) for a in line.split()])
        assert len(levels) == N
        
        yield N, levels
    f.close()

def play(N, levels):
    # rule 1: if you can play b, play b from min b to max b
    # rule 2: if you cannot play b, play a from max b to min b
    # rule 3: otherwise not good
    
    MAX = 9999
    played_a = [0] * N
    played_b = [0] * N
    As = [a for a, b in levels]
    Bs = [b for a, b in levels]
    stars = 0
    plays = 0
    while True:
        if sum(played_b) == N:
            break
        # can play b
        if stars >= min(Bs):
            for b in range(N):
                if Bs[b] <= stars and played_b[b] == 0:
                    played_b[b] = 1
                    if played_a[b]:
                        stars += 1
                    else:
                        stars += 2
                        played_a[b] = 1
                        As[b] = MAX
                    Bs[b] = MAX
                    plays += 1
            continue
        # cannot play b
        b = None
        if stars >= min(As):
            max_b = -1
            which_max_b = -1
            for a in range(N):
                if As[a] <= stars and played_a[a] == 0:
                    if Bs[a] > max_b:
                        max_b = Bs[a]
                        which_max_b = a
            a = which_max_b
            played_a[a] = 1
            stars += 1
            As[a] = MAX
            plays += 1
            continue
        # both cannot play
        return 'Too Bad'

    return plays

def solve(N, levels, case):
    res = play(N, levels)
    print "Case #%d:" % case, res
    

def main(filename):
    case = 1
    for N, levels in parse(filename):
        solve(N, levels, case)
        case += 1
    

if __name__ == '__main__':
    main(sys.argv[1])