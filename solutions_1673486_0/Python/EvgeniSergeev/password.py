
import sys

si = sys.stdin


T = int(si.readline())

for tcase in range(T):
    A, B = map(int, si.readline().split())
    ps = map(float, si.readline().split())

    Pfirst_i_ok = [1] * (A+1)
    for i in range(len(ps)):
        Pfirst_i_ok[i+1] = Pfirst_i_ok[i] * ps[i]

    best = 2 + B
    for backspace in range(0, A+1):
        works_cost = (2*backspace + B-A + 1)
        e_works = Pfirst_i_ok[A-backspace] * works_cost
        e_doesnt = (1 - Pfirst_i_ok[A-backspace]) * (works_cost + B+1)
        candidate = e_works + e_doesnt
        if candidate < best:
            best = candidate

    print "Case #%d:" % (tcase+1), best
