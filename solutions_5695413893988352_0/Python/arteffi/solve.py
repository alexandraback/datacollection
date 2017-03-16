INPUT_PATH = 'small.in'

def main():
    #test_cases = [('5?0', '5?7')] #parse_input(INPUT_PATH)
    test_cases = parse_input(INPUT_PATH)
    solutions = []
    for i, test_case in enumerate(test_cases):
        print('-' * 10)
        print('Test case', i)
        a, b = test_case
        solution = solve(a, b)
        print(test_case, '->', solution)
        solutions.append(solution)
    output_solutions(solutions)


def parse_input(path):
    with open(path) as f:
        n = int(f.readline())
        lines = f.read().split('\n')
    test_cases = [line.split() for line in lines][:n]
    assert n == len(test_cases)
    return test_cases


def output_solutions(solutions):
    with open('output', 'w') as f:
        for i, solution in enumerate(solutions, 1):
            f.write('Case #{i}: {a} {b}\n'.format(i=i, a=solution[0], b=solution[1]))


def solve(a, b):
    n = len(a)
    # div .. prvni pozice, na ktere se budou lisit
    possibilities = []
    for div in range(n + 1):
        if div == n:
            fa = fill(a, b, div, None)
            fb = fill(b, a, div, None)
            score_a, score_b = int(fa), int(fb)
            score = abs(score_a - score_b)
            possibilities.append((score, score_a, score_b, fa, fb))
            break
        da, db = a[div], b[div]
        differ = da != '?' and db != '?' and da != db

        fa = fill(a, b, div, True)
        fb = fill(b, a, div, False)
        score_a, score_b = int(fa), int(fb)
        score = abs(score_a - score_b)
        possibilities.append((score, score_a, score_b, fa, fb))

        fa = fill(a, b, div, False)
        fb = fill(b, a, div, True)
        score_a, score_b = int(fa), int(fb)
        score = abs(score_a - score_b)
        possibilities.append((score, score_a, score_b, fa, fb))

        if differ:
            break
    #print(possibilities)
    best = min(possibilities)
    return best[3], best[4]


def fill(x, y, div, higher):
    fx = []
    for i, (dx, dy) in enumerate(zip(x, y)):
        if dx != '?':
            fx.append(dx)
        elif i < div:
            fx.append(dy if dy != '?' else '0')
        elif i == div:
            if higher:
                if dy != '?' and dy != '9':
                    fx.append(str(int(dy) + 1))
                else:
                    fx.append('1')
            else:
                if dy != '?' and dy != '0':
                    fx.append(str(int(dy) - 1))
                else:
                    fx.append('0')
        else:
            if higher:
                fx.append('0')
            else:
                fx.append('9')
    return ''.join(fx)



"""
def solve(a, b):
    state = 'initial'
    ca, cb = [], []
    for da, db in zip(a, b):
        if state == 'initial':
            if da != '?' and db != '?':
                if int(da) > int(db):
                    state = 'a>b'
                elif int(da) < int(db):
                    state = 'a<b'
            elif db != '?':
                da = db
            elif da != '?':
                db = da
            else:
                da, db = '0', '0'
            ca.append(da)
            cb.append(db)
        elif state == 'a>b':
            ca.append('0' if da == '?' else da)
            cb.append('9' if db == '?' else db)
        elif state == 'a<b':
            ca.append('9' if da == '?' else da)
            cb.append('0' if db == '?' else db)
        else:
            raise ValueError('illegal state')
    return ''.join(ca), ''.join(cb)
"""

if __name__ == '__main__':
    main()
