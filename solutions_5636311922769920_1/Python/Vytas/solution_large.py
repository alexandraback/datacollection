import problem


class Fractiles(problem.Problem):

    def solve(self, case):

        def get_representative_point(K, C, gold_pos):
            if C == 1:
                return gold_pos
            return (gold_pos * K ** (C-1) +
                    get_representative_point(K, C-1, (gold_pos+1) % K))

        def get_representative_points(K, C):
            return tuple(get_representative_point(K, C, gold_pos) + 1
                         for gold_pos in range(K))

        K, C, S = case
        solution = get_representative_points(K, C)

        # Try to distribute the representative points evenly
        selected = []
        index = 0
        while index < K:
            selected.append(solution[index])
            index += C

        if len(selected) > S:
            return 'IMPOSSIBLE'
        return ' '.join(map(str, selected))

    def parse_case(self, lines):
        case = map(int, lines.next().split())
        assert len(case) == 3
        return case


if __name__ == '__main__':
    Fractiles.run()
