import re


def number_of_flips(pancakes):
    last = pancakes[-1]
    diffs = len(re.findall('(\+-)', pancakes) + re.findall('(-\+)', pancakes))
    return diffs + (1 if last == '-' else 0)


def main():
    case = int(input())
    for i in range(case):
        pancakes = input()
        print('Case #{}: {}'.format(i+1, number_of_flips(pancakes)))


main()
