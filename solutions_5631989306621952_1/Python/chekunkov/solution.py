# -*- coding: utf-8 -*-
import sys


def solution(line):
    result = line[0]
    for l in line[1:]:
        if result[0] <= l:
            result = l + result
        else:
            result += l
    return result


def main():
    _ = next(sys.stdin) # num test cases
    case_num = 1
    for line in sys.stdin:
        val = line.strip()
        print "Case #%s:" % case_num, solution(val)
        case_num += 1


if __name__ == '__main__':
    main()
