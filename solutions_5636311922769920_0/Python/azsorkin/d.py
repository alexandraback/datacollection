#! /usr/bin/env python

def main():
    num_cases = int(raw_input())
    for case in range(1, num_cases + 1):
        k, c, s = map(int, raw_input().split())
        answer = get_answer(k, c, s)
        print 'Case #{}: {}'.format(case, answer)


def get_answer(k, c, s):
    if s == k:
        slope = sum(k**i for i in range(c))
        return ' '.join(map(str, [1 + i * slope for i in range(k)]))
    else:
        return "IMPOSSIBLE"


if __name__ == '__main__':
    main()
