import problem

SAMPLE = """5
-
-+
+-
+++
--+-
"""


class Pancakes(problem.Problem):

    def __init__(self):
        super(Pancakes, self).__init__()
        self.table = self.build_table()

    @staticmethod
    def flip(pancakes, n):
        return (''.join(
            '+' if pancake == '-' else '-'
            for pancake in reversed(pancakes[:n])) + pancakes[n:])

    def build_table(self, max_length=10):
        table = {}
        combinations = set()

        for length in range(1, max_length + 1):
            for value in xrange(1 << max_length):
                pancakes = ''
                bits = value
                for i in xrange(length):
                    pancakes += '+' if bits % 2 == 0 else '-'
                    bits >>= 1
                combinations.add(pancakes)

        for pancakes in combinations:
            if all(pancake == '+' for pancake in pancakes):
                table[pancakes] = 0

        while True:
            previous = table.copy()

            for pancakes in combinations:
                for n in xrange(1, len(pancakes) + 1):
                    flipped = self.flip(pancakes, n)
                    if flipped in table:
                        if pancakes in table:
                            table[pancakes] = min(
                                table[pancakes], table[flipped] + 1)
                        else:
                            table[pancakes] = table[flipped] + 1

            if table == previous:
                break

        assert set(table) == combinations
        return table

    def solve(self, case):
        return self.table[case]

    def parse_case(self, lines):
        return lines.next().strip()


if __name__ == '__main__':
    # Pancakes.run_sample(SAMPLE)
    Pancakes.run()
