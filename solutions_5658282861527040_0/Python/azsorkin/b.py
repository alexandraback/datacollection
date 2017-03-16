#! /usr/bin/env python

def main():
    with open('b.in', 'r') as fin, open('b.out', 'w') as fout:
        num_cases = int(fin.readline())
        for case in range(1, num_cases + 1):
            A, B, K = map(int, fin.readline().split())
            answer = solve(A, B, K)
            fout.write('Case #{0}: {1}\n'.format(case, answer))
    return


def solve(A, B, K):
    """Brute Force"""
    answer = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K:
                answer += 1
    return answer


if __name__ == '__main__':
    main()
