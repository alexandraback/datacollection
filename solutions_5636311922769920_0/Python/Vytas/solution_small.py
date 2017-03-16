import problem

SAMPLE = """5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
"""


class Fractiles(problem.Problem):

    def solve(self, case):
        def get_representative_point(K, C, gold_pos):
            if C == 1:
                return gold_pos
            ret_part = (gold_pos + 1) % K
            return (ret_part * K ** (C-1) +
                    get_representative_point(K, C-1, gold_pos))

        def get_representative_points(K, C):
            return tuple(get_representative_point(K, C, gold_pos) + 1
                         for gold_pos in range(K))

        K, C, S = case
        # assert S == K
        return ' '.join(map(str, get_representative_points(K, C)))

    def parse_case(self, lines):
        case = map(int, lines.next().split())
        assert len(case) == 3
        return case


if __name__ == '__main__':
    # Fractiles.run_sample(SAMPLE)
    Fractiles.run()
