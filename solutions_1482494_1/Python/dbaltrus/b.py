import sys

data = sys.stdin.readlines()

i = 1
for c in range(1, int(data[0]) + 1):
    N = int(data[i])
    i += 1
    ba = [(0, 0)] * N
    collected = [0] * N
    for t in range(N):
        a, b = [int(x) for x in data[i].split()]
        ba[t] = (b, a)
        i += 1
    ba.sort()
    ba.reverse()
    progressed = True
    stars = 0
    tries = 0
    while progressed:
        progressed = False
        for l in range(N):
            if collected[l] < 2 and ba[l][0] <= stars:
                stars += 2 - collected[l]
                tries += 1
                collected[l] = 2
                progressed = True
                break
        if not progressed:
            for l in range(N):
                if collected[l] < 1 and ba[l][1] <= stars:
                    stars += 1
                    tries += 1
                    collected[l] = 1
                    progressed = True
                    break
    if stars < N * 2:
        answer = "Too Bad"
    else:
        answer = tries
    print('Case #', c, ': ', answer, sep='')
