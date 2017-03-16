import sys
from itertools import product

def run_test(case_number, generator):
    k, l, s = [int(x) for x in next(generator).split()]
    keyboard = next(generator).rstrip()
    target = next(generator).rstrip()

    keyboard_set = set()
    target_set = set()

    for c in keyboard:
        keyboard_set.add(c)
    
    for c in target:
        target_set.add(c)
    
    if keyboard_set >= target_set:
        bananas = []
        for possible_combination in product(keyboard, repeat=s):
            possible_combination = ''.join(possible_combination)
            banana = 0
            start = 0
            index = possible_combination.find(target)
            while(index >= 0):
                banana += 1
                start = index + 1
                index = possible_combination.find(target, start)
            bananas.append(banana)
        needed_bananas = max(bananas)
        average = sum(bananas) / len(bananas)
        print('Case #%d: %s' % (case_number, needed_bananas - average))
    else:
        print('Case #%d: %f' % (case_number, 0.0))

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