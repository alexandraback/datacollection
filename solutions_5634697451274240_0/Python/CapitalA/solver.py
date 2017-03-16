import sys

def get_state(pancake, is_stack_reversed):
    if pancake == '+':
        return not is_stack_reversed
    return is_stack_reversed

def solve_case(pancakes):
    is_stack_reversed = False
    reversals = 0
    for i in xrange(len(pancakes) - 1, -1, -1):
        if not get_state(pancakes[i], is_stack_reversed):
            reversals += 1
            is_stack_reversed = not is_stack_reversed
    return reversals

def main(filename):
    with open(filename, 'r') as fd:
        pancakes = [line.strip() for line in fd.readlines()]
    for j in xrange(1, len(pancakes)):
        print 'Case #%d: %d' % (j, solve_case(pancakes[j]))

if __name__ == '__main__':
    main(sys.argv[1])
