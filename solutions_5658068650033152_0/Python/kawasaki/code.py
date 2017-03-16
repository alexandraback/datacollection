# -*- coding: utf-8 -*-


def count_stones(grids):
    W, H = len(grids[0]), len(grids)
    stones = set()
    for y in xrange(H):
        values = [x for x in xrange(W) if grids[y][x]]
        if values:
            stones.add((min(values), y))
            stones.add((max(values), y))
    for x in xrange(W):
        values = [y for y in xrange(H) if grids[y][x]]
        if values:
            stones.add((x, min(values)))
            stones.add((x, max(values)))
    return len(stones)


def dbg(grids):
    print '\n'.join(''.join(str(x) for x in row) for row in grids)


T = int(raw_input())
for test_case in xrange(1, T + 1):
    N, M, K = map(int, raw_input().split())
    W, H = (M, N) if N <= M else (N, M)
    assert H <= W

    if K <= 4:
        answer = K
    elif W * H - 4 <= K:
        answer = (W - 2 + H - 2) * 2
        answer += 4 - (N * M - K)
    else:
        grids = [[0] * W for i in xrange(H)]
        ox, oy = (W - 1) / 2, (H - 1) / 2
        area = 0

        answer = None

        size = 0
        grids[oy][ox] = 1
        area += 1

        while answer is None:
            size += 1
            cands = []
            cands.append((size, 0))
            for sx in xrange(size - 1, 0, -1):
                cands.append((sx, size - sx))
                cands.append((sx, -(size - sx)))
            for s in xrange(size):
                cands.append((-s, size - s))
            for s in xrange(size):
                cands.append((-s, -(size - s)))
            cands.append((-size, 0))
            assert len(cands) == size * 4

            if W % 2 == 1 and H % 2 == 0:
                cands = [(-dy, dx) for dx, dy in cands]

            while cands:
                dx, dy = cands.pop(0)
                px, py = ox + dx, oy + dy
                if 0 <= px < W and 0 <= py < H:
                    grids[py][px] = 1
                    area += 1
                    if area == K:
                        answer = count_stones(grids)
                        break
                if answer:
                    break

    print 'Case #{}: {}'.format(test_case, answer)
