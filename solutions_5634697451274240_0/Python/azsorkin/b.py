#! /usr/bin/env python

def main():
    num_cases = int(raw_input())
    for case in range(1, num_cases + 1):
        pancakes = raw_input()
        answer = get_num_flips(pancakes)
        print 'Case #{}: {}'.format(case, answer)


def get_num_flips(pancakes):
    # Idea: keep flipping longest prefix
    flips = 0
    start_state = pancakes[0]
    for pan, cake in zip(pancakes, pancakes[1:]):
        if pan != cake:
            flips += 1
    if (start_state == '+' and flips % 2) or (start_state == '-' and flips % 2 == 0):
        flips += 1
    return flips


if __name__ == '__main__':
    main()
