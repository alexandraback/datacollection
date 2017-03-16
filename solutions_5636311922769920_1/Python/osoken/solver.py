# coding: UTF-8

import sys
import math


class Solver(object):
    def __init__(self, k, c, s):
        self._k = k
        self._c = c
        self._s = s

    def forward(self, q, r):
        return q * self._k + r

    def backward(self, x, d):
        if d == 0:
            return []
        u = self._k ** (d)
        y1 = x % u
        y2 = x // u
        if y1 == y2:
            return (y1,)
        return (y1, y2)

    def solve(self):
        unit = self._c + 1
        nperson = int(math.ceil(float(self._k) / float(unit)))
        if nperson > self._s:
            return None
        answers = []
        for pc in range(nperson):
            base = pc * unit
            next_target = base
            for d in range(0, self._c):
                next_target = self.forward(next_target, (d+1+base) % self._k)
            answers.append(next_target)
        return answers

if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn, prob in enumerate(sys.stdin.readlines()):
        (k, c, s) = map(int, prob.strip().split(' '))
        ans = Solver(k, c-1, s).solve()
        if ans is None:
            sys.stdout.write('Case #%d: IMPOSSIBLE\n' % (cn+1))
        else:
            sys.stdout.write('Case #%d: %s\n' % ((cn+1), ' '.join(
                map(lambda x: str(x + 1), ans))))
