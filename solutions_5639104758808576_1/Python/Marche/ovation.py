#!/usr/bin/python3

import sys

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as f:
        T = int(f.readline())
        for test in range(1, T+1):
            Smax_str, shy_str = f.readline().split()
            Smax = int(Smax_str)
            shy = list(map(int, list(shy_str)))
            standing = shy[0]
            invited = 0
            for i in range(1, Smax+1):
                if standing < i:
                    invited += 1
                    standing += 1
                standing += shy[i]
            print("Case #{}: {}".format(test, invited))
