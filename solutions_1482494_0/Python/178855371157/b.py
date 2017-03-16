
import heapq

T = input()
for t in range(1,T+1):
    N = input()
    level = []
    for i in xrange(0,N):
        [ai, bi] = [int(x) for x in raw_input().split()]
        level.append([ai, bi, 0])
    level.sort()

    level2 = [(lev[1], lev) for lev in level]
    level2.sort()

    level2.append((3*N, ()))
    level.append([3*N, 3*N, 0])                  

    stars = 0
    answer = 0
    pos2 = 0
    pos1 = 0
    avail1 = []

    while True:
        old_stars = stars
        old_pos1 = pos1
        old_pos2 = pos2

        # Take all available 2-star wins.
        while (pos2 < N) and (level2[pos2][0] <= stars):
            assert level2[pos2][0] <= level2[pos2+1][0]
            assert level2[pos2][0] <= stars
            answer += 1
            lev = level2[pos2][1]
            assert lev[1] <= stars
            assert lev[2] < 2
            assert lev[2] >= 0
            stars += 2 - lev[2]
            lev[2] = 2
            pos2 += 1

        if pos2 == N:
            # We win.
            break

        # Which 1-star wins are available?
        while (pos1 < N) and (level[pos1][0] <= stars):
            assert level[pos1][0] <= level[pos1+1][0]
            if level[pos1][2] == 0:
                heapq.heappush(avail1, (-level[pos1][1], level[pos1]))
            pos1 += 1

        # Take 1-star wins until another 2-star win is possible.
        while (level2[pos2][0] > stars) and avail1:
            lev = heapq.heappop(avail1)[1]
            assert lev[0] <= stars
            assert (lev[2] == 0) or (lev[1] <= stars)
            assert lev[2] != 1
            assert lev[1] >= max([lev[1]] + [z[1] for (x,z) in avail1])
            if lev[2] == 0:
                answer += 1
                lev[2] = 1
                stars += 1

        if (stars == old_stars) and (pos1 == old_pos1) and (pos2 == old_pos2):
            assert level2[pos2][0] > stars
            assert not avail1
            # We lost.
            break

    if pos2 == N:
        print "Case #{}: {}".format(t, answer)
        assert answer >= N
    else:
        print "Case #{}: Too Bad".format(t)

    assert answer <= 2*N

