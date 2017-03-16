#!/usr/bin/env python3


def testcase(t):
    s_max, shyness = input().split()
    num_friends = 0
    curr_sum = 0
    for (i, s_i) in enumerate(shyness):
        if curr_sum < i:
            diff = i - curr_sum
            num_friends += diff
            curr_sum += diff

        curr_sum += int(s_i)
    print("Case #{}: {}".format(t, num_friends))


def main():
    T = int(input())
    for t in range(T):
        testcase(t+1)


if __name__ == '__main__':
    main()
