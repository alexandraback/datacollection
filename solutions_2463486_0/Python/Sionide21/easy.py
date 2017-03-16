#! /usr/bin/env python
import template
import math


class App(template.Application):
    def solve(self):
        start, end = self.ints_line
        num = 0
        for x in range(start, end + 1):
            sqrt = math.sqrt(x)
            if int(sqrt) == sqrt:
                s = str(x)
                s2 = str(int(sqrt))
                if s == s[::-1] and s2 == s2[::-1]:
                    num += 1
        return num


if __name__ == '__main__':
    App()
