import problem


class Pancakes(problem.Problem):

    @staticmethod
    def flip(pancakes, n):
        return (''.join(
            '+' if pancake == '-' else '-'
            for pancake in reversed(pancakes[:n])) + pancakes[n:])

    def solve(self, case):
        if case == '':
            return 0
        if case.endswith('+'):
            return self.solve(case[:-1])
        plus_count = 0
        while case[plus_count] == '+':
            plus_count += 1
        return self.solve(self.flip(case, plus_count or len(case))) + 1

    def parse_case(self, lines):
        return lines.next().strip()


if __name__ == '__main__':
    Pancakes.run()
