import random


def gorandom(E, R, N, v):
    table = [[0] * (E + 1) for _ in xrange(N)]
    R = min(R, E)
    for i in xrange(N):
        for prev_e in xrange(0, E + 1):
            if i == 0:
                prev_best_gain = 0
            else:
                prev_best_gain = table[i - 1][prev_e]

            for energy_spent in xrange(0, prev_e + 1):
                current_energy = prev_e
                current_energy -= energy_spent
                current_energy += R
                current_energy = min(current_energy, E)
                current_energy = max(current_energy, 0)
                table[i][current_energy] = max(table[i][current_energy],
                                               prev_best_gain + energy_spent * v[i])

    return max([max(x) for x in table])


def main():
    T = int(raw_input())
    for case_num in xrange(1, T + 1):
        E, R, N = map(int, raw_input().split())
        v = map(int, raw_input().split())
        total_gain = -1
        # for i in xrange(1000000):
        total_gain = max(total_gain, gorandom(E, R, N, v))

        print "Case #{}: {}".format(case_num, total_gain)


if __name__ == "__main__":
    import b
    b.main()
