#!/usr/bin/env python3


table = {
  1: {1:  1, 2:  2, 3:  3, 4:  4},
  2: {1:  2, 2: -1, 3:  4, 4: -3},
  3: {1:  3, 2: -4, 3: -1, 4:  2},
  4: {1:  4, 2:  3, 3: -2, 4: -1},
}

trans = {'i': 2, 'j': 3, 'k': 4}

def testcase():
    L, X = map(int, input().split())
    my_str = input()
    my_str *= X

    subs = []
    idx_i = -1
    idx_j = -1

    res = 1
    for (idx, c) in enumerate(my_str):
        if res < 0:
            res = -table[-res][trans[c]]
        else:
            res = table[res][trans[c]]
        if res == 2 and idx_i == -1:
            idx_i = idx
        elif res == 4 and idx_i != -1:
            idx_j = idx
        subs.append(res)

    if subs[-1] != -1:
        return "NO"

    if idx_i != -1 and idx_j != -1 and idx_i < idx_j:
        return "YES"
    else:
        return "NO"


def main():
    T = int(input())
    for t in range(T):
        print("Case #{}: {}".format(t+1, testcase()))


if __name__ == '__main__':
    main()
