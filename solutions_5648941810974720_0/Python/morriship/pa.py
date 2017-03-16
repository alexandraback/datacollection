#!/usr/bin/pypy
# -*- coding: utf-8 -*-


def dec(num, word, count):
    if count:
        for char in word:
            num[char] -= count
    return count


word = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

def kill0(num):
    count = num.get('Z', 0)
    return dec(num, word[0], count)


def kill2(num):
    count = num.get('W', 0)
    return dec(num, word[2], count)


def kill4(num):
    count = num.get('U', 0)
    return dec(num, word[4], count)


def kill6(num):
    count = num.get('X', 0)
    return dec(num, word[6], count)


def kill8(num):
    count = num.get('G', 0)
    return dec(num, word[8], count)

def kill1(num):
    count = num.get('O', 0)
    return dec(num, word[1], count)


def kill1(num):
    count = num.get('O', 0)
    return dec(num, word[1], count)


def kill3(num):
    count = num.get('R', 0)
    return dec(num, word[3], count)


def kill5(num):
    count = num.get('F', 0)
    return dec(num, word[5], count)


def kill7(num):
    count = num.get('S', 0)
    return dec(num, word[7], count)


def solve():
    num = {}
    ans = [0] * 10
    s = raw_input()
    for ch in s:
        num[ch] = num.get(ch, 0) + 1

    ans[0] = kill0(num)
    ans[2] = kill2(num)
    ans[4] = kill4(num)
    ans[6] = kill6(num)
    ans[8] = kill8(num)
    ans[1] = kill1(num)
    ans[3] = kill3(num)
    ans[5] = kill5(num)
    ans[7] = kill7(num)
    ans[9] = num.get('I', 0)
    result = ''
    for i in xrange(10):
        result += str(i) * ans[i]
    return result


if __name__ == '__main__':
    output = 'Case #{}: {}'

    t = int(raw_input())
    for i in xrange(1, t + 1):
        print output.format(i, solve())
