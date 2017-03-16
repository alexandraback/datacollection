# kingdom.py
# Solves Kingdom Rush problem for Google Code jam

import heapq

lines = open("B-small-attempt1.in", "r").read().split("\n")
fout = open("kingdom.out", "w")

cases = int(lines[0])
current = 1

for c in range(cases):
    levels = int(lines[current])
    current += 1

    starmounts = []

    for j in range(levels):
        vals = lines[current].split()
        current += 1

        starmounts.append((int(vals[0]), int(vals[1])))

    #print(starmounts)

    player = (0, 0, (0,)*levels)

    states = []

    heapq.heappush(states,  player)
    used = set()

    done = False
    times = 0

    while not done and len(states) > 0:
        p = heapq.heappop(states)
        #print(p)

        if p[1] == levels*2:
            done = True
            times = p[0]
        else:
            used.add(p[2])
            for i in range(len(starmounts)):
                if p[2][i] != 2 and p[1] >= starmounts[i][1]:
                    n_p = p[2][:i] + (2,) + p[2][i+1:]
                    if n_p not in used:
                        used.add(n_p)
                        heapq.heappush(states, (p[0] + 1, p[1] + 2 - p[2][i],
                                                n_p))
                elif p[2][i] == 0 and p[1] >= starmounts[i][0]:
                    n_p = p[2][:i] + (1,) + p[2][i+1:]
                    if n_p not in used:
                        used.add(n_p)
                        heapq.heappush(states, (p[0] + 1, p[1] + 1,
                                                n_p))
                

    if done:
        fout.write("Case #%d: %d\n" % (c + 1, times))
    else:
        fout.write("Case #%d: Too Bad\n" % (c + 1) )

fout.close()

