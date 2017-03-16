import problem

SAMPLE = """5
0
1
2
11
1692
"""


class CountingSheep(problem.Problem):

    def solve(self, case):
        if case == 0:
            return 'INSOMNIA'

        seen = set()
        i = 0

        while True:
            i += 1
            N = i * case
            seen.update(str(N))
            if len(seen) == 10:
                return N

    def parse_case(self, lines):
        return int(lines.next())


if __name__ == '__main__':
    # CountingSheep.run_sample(SAMPLE)
    CountingSheep.run()
