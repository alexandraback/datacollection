import os


CUR_DIR = os.path.dirname(os.path.realpath(__file__))


def read_test(f):
    tests = []
    with open(f, 'r') as ifs:
        for case in ifs.read().split('\n')[1:]:
            if case.strip():
                tests.append(tuple(case.strip().split()))
    return tests


def naive(l, r):
    l = list(l)
    r = list(r)
    if len(l) > 3:
        return '0'

    def gen_next(x):
        c = sum(1 for c in x if c == '?')
        M = int(10**c)
        for q in range(M):
            s = str(q).zfill(c)
            y = x[:]
            k = 0
            for i in range(len(y)):
                if y[i] == '?':
                    y[i] = s[k]
                    k += 1
            yield int(''.join(y))
    
    best_left, best_right = 1e100, 2e100
    for x in gen_next(l):
        for y in gen_next(r):
            dif = abs(x - y)
            if dif < abs(best_left - best_right):
                best_left = x
                best_right = y
            elif dif == abs(best_left - best_right):
                if x < best_left:
                    best_left = x
                    best_right = y
                elif x == best_left and y < best_right:
                    best_left = x
                    best_right = y
    return ' '.join([str(best_left).zfill(len(l)), str(best_right).zfill(len(r))])
    

def solve_case(case):
    print(case)
    return naive(case[0], case[1])


def solve(cases):
    for case in cases:
        yield solve_case(case)
            

def save(f, asnwers):
    with open(f, 'w') as ofs:
        for case, ans in enumerate(asnwers):
            ofs.write('Case #%d: %s\n' % (case + 1, str(ans))) 


def main():
    for f in os.listdir(CUR_DIR):
        if f.startswith('B') and '.in' in f and os.path.isfile(CUR_DIR + os.path.sep + f) or f == 'input.in':
            print(f)
            tests = read_test(f)
            answers = solve(tests)
            save(CUR_DIR + os.path.sep + f.replace('.in', '.out'), answers)
            print('Done!')


if __name__ == '__main__':
    main()
