import sys
from functools import reduce

def run_test(case_number, generator):
    r, c, w = [int(x) for x in next(generator).split()]

    hits_per_row = int(c / w)
    rest = c % w
    hits = hits_per_row * (r - 1)

    last_row = hits_per_row - 1

    open_fields = c - (last_row * w)
    # overlap = open_fields - (open_fields - w) * 2

    additional = min(w + 1, open_fields)

    result = hits + last_row + additional

    print('Case #%d: %d' % (case_number, result))

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