from collections import namedtuple, defaultdict

class Tribe:
    def __init__(self, idx, day, attacks, w, e, strength,
                 delta_d, delta_p, delta_s):
            self.idx = idx
            self.day = day
            self.attacks = attacks
            self.w = w
            self.e = e
            self.strength = strength
            self.delta_d = delta_d
            self.delta_p = delta_p
            self.delta_s = delta_s

    def attacked(self, wall):
        res = False
        for i in range(2 * self.w, 2 * self.e + 1):
            if wall[i] < self.strength:
                res = True
            wall[i] = self.strength

        self.attacks -= 1
        self.w += self.delta_p
        self.e += self.delta_p
        self.strength += self.delta_s
        self.day += self.delta_d
        return res


def solve():
    N = int(input())
    tribes = []
    wall = defaultdict(int)
    for i in range(N):
        row = [int(x) for x in input().split()]
        tribes.append(Tribe(i, *row))

    cnt = 0
    while True:
        tribes = sorted([t for t in tribes if t.attacks > 0],
                        key=lambda t: t.day)
        tribes = list(tribes)
        if not tribes:
            break

        if tribes[0].attacked(wall):
            cnt += 1
    return cnt


def main():
    T = int(input())
    for t in range(T):
        res = solve()
        print('Case #{}: {}'.format(t + 1, res))


if __name__ == '__main__':
    main()
