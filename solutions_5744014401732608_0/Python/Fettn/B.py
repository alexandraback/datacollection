import sys

def sum_n(n):
    if (n == 0):
        return 0
    else:
        return n + sum_n(n - 1)

def run_test(case_number, generator):
    b, m = (int(x) for x in next(generator).split())
    max_number = sum_n(b - 1)
    result = 'IMPOSSIBLE'
    if max_number >= m:
        result = 'POSSIBLE'
        rest = m
        matrix = []
        if m > (b - 1):
            matrix.append(('0' + '1' * (b - 1)))
            rest -= (b-1)
        else:
            matrix.append(('0' * (b - m) + '1' * m))
            rest = 0
        for building in range(1, b - 1):
            current = b - (building + 2)
            line = '0' * (building + 1)
            if rest >= current:
                rest -= current
                line += '1' * (current + 1)
            else:
                line += '0' * (b - building - rest - 2) + '1' * (rest + 1)
                rest = 0
            matrix.append(line)
        matrix.append('0' * b)
    
    print('Case #%d: %s' % (case_number, result))
    if result == 'POSSIBLE':
        for y in range(b):
            print(' '.join(matrix[y]))

def main():
    generator = get_file()
    number_of_tests = int(next(generator))
    for test in range(1, number_of_tests + 1):
        run_test(test, generator)

def get_file():
    for line in sys.stdin:
        yield line
        
if __name__ == '__main__':
    main()