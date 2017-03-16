import sys

INPUT_FILE = 'C:\Users\Marius\Downloads\C-small-attempt0 (1).in'

def solve(numbers):
    possible_sums = {}
    for n in numbers:
        new_sums = {n : [tuple([n])]}
        for k, v in possible_sums.items():
            new_sums[k + n] = [tuple(list(v0) + [n]) for v0 in v]
        for k, v in new_sums.items():
            if k not in possible_sums.keys():
                possible_sums[k] = v
            else:
                first = ' '.join([str(x) for x in possible_sums[k][0]])
                second = ' '.join([str(x) for x in v[0]])
                return '\n'.join([first, second])
    return 'Impossible'

def main():
    try:
        file = INPUT_FILE
    except NameError:
        file = 'SampleTests.txt'
    fh = open(file)
    number_of_cases = int(fh.readline())
    for case in range(number_of_cases):
        numbers = [int(x) for x in fh.readline().split()] 
        result = solve(numbers[1:])
        print 'Case #%s:\n%s' % (case + 1, result)

if __name__ == '__main__':
    try:
        sys.stdout = open('Result.txt', 'w')
        main()
    finally:
        sys.stdout = sys.__stdout__ 