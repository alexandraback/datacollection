#!/usr/bin/env python3
# -*- coding: utf-8 -*-


GOAL = set(range(10))


class InsomniaError(Exception):
    pass


def enumerate_digits(n):
    return set(map(int, str(n)))


def compute_last_number(start):
    if start == 0:
        raise InsomniaError
    digits = enumerate_digits(start)
    i = 1
    while digits != GOAL:
        i += 1
        x = start * i
        digits.update(enumerate_digits(x))
    return x


def main():
    t = int(input())
    for i in range(1, t + 1):
        try:
            answer = compute_last_number(int(input()))
        except InsomniaError:
            answer = "INSOMNIA"
        finally:
            print("Case #{}: {}".format(i, answer))


if __name__ == '__main__':
    main()
