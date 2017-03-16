#!/usr/bin/env python3.4
import sys
import math

if __name__ == '__main__':
    for test_case in range(int(sys.stdin.readline())):
        sys.stdout.write('Case #{}: '.format(test_case + 1))
        coin_num, denom_num, value = map(int, sys.stdin.readline().split())
        denoms = list(sorted(map(int, sys.stdin.readline().split())))
        cnt = 0
        next_num = None
        while True:
            holes = [False] * (value + 1)
            for i in denoms:
                for j in range(value, 0, -1):
                    if holes[j] == True and i + j <= value:
                        holes[i + j] = True
                holes[i] = True
            for j in range(1, value + 1):
                if holes[j] == False:
                    next_num = j
                    break
            if next_num == None:
                print(cnt)
                break
            else:
                denoms.append(next_num)
                next_num = None
                cnt += 1

