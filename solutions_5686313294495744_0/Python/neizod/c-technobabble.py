#!/usr/bin/env python3


def test(topics):
    first = set()
    second = set()
    count = 0
    for topic in topics:
        fs, sc = topic.split()
        if fs in first and sc in second:
            count += 1
        else:
            first |= {fs}
            second |= {sc}
    return count


def main():
    for case in range(int(input())):
        topics = [input() for _ in range(int(input()))]
        print('Case #{}: {}'.format(case+1, test(topics)))


if __name__ == '__main__':
    main()
