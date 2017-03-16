import sys

def play(N, star1, star2):
    # print N
    # print star1
    # print star2
    levels = set(range(N))
    notdone = set(range(N))
    done1 = set()
    done2 = set()
    stars = 0
    moves = 0
    while done2 != levels:
        moves += 1
        double = False
        options = []
        for level in notdone:
            if star2[level] <= stars:
                options.append((2, 2, star2[level], level))
                double = True
                break
            elif star1[level] <= stars:
                options.append((1, 1, star2[level], level))
        if not double:
            for level in done1:
                if star2[level] <= stars:
                    options.append((1, 2, star2[level], level))
                    break
        if not options:
            return 'Too Bad'
        options.sort(reverse=True)
        best = options[0]
        # print best
        (gained, st, _, level) = best
        stars += gained
        if st == 1:
            done1.add(level)
            notdone.discard(level)
        elif st == 2:
            done2.add(level)
            done1.discard(level)
            notdone.discard(level)
    return moves

data = open('B-large.in', 'r')
T = int(data.readline().strip())
for case in range(1, T+1):
    N = int(data.readline().strip())
    star1 = []
    star2 = []
    for i in range(N):
        (a, b) = tuple(map(int, data.readline().split()))
        star1.append(a)
        star2.append(b)
    print 'Case #{}: {}'.format(case, play(N, star1, star2))
    sys.stdout.flush()
