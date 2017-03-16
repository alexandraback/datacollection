#! /usr/bin/env python
import template


class App(template.Application):

    def solve(self):
        N, M = self.ints_line
        lines = [self.ints_line for _ in range(N)]

        rows = [max(line) for line in lines]
        cols = [max(line) for line in zip(*lines)]

        sol = True

        for x, line in enumerate(lines):
            for y, val in enumerate(line):
                sol = sol and min(rows[x], cols[y]) <= val

        if sol:
            return "YES"
        else:
            return "NO"


if __name__ == '__main__':
    App()
