#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np

def solver(bffs):

    students = [i + 1 for i in range(len(bffs))]
    # circle, students = right_sit(1, students, bffs)

    max_circle = []
    for s in students:
        # print s
        circle1, left_students = right_sit(s, students, bffs)
        # print circle1
        max_circle2 = []
        if bffs[circle1[-1] - 1] == circle1[-2]:
            # print 'cycle!'
            valid_tail = backward_bffs(circle1[-1], bffs)
            for j in left_students:
                circle2, _ = right_sit(j, left_students, bffs)
                if circle2[-1] in valid_tail:
                    if len(circle2) > len(max_circle2):
                        max_circle2 = circle2
        elif bffs[circle1[-1] - 1] != circle1[0]:
            circle1.pop()
            valid_tail = backward_bffs(circle1[-1], bffs)
            for j in left_students:
                circle2, _ = right_sit(j, left_students, bffs)
                if circle2[-1] in valid_tail:
                    if len(circle2) > len(max_circle2):
                        max_circle2 = circle2

        if len(max_circle2) > 0:
            max_circle2.reverse()
            circle = circle1 + max_circle2
        else:
            circle = circle1

        if len(circle) > len(max_circle):
            max_circle = circle

    return max_circle


def right_sit(start, students, bffs):
    left_students = students[:]
    circle = []
    while True:
        if start not in left_students:
            break
        else:
            circle.append(start)
            left_students.remove(start)
            bff = bffs[start-1]  # zero-based
            start = bff
    return circle, left_students

def backward_bffs(s, bffs):
    is_back_bff = [i == s for i in bffs]
    back_bffs = [i+1 for i, x in enumerate(is_back_bff) if x]
    return back_bffs

if __name__ == "__main__":


    testcases = input()
    for caseNr in xrange(1, testcases+1):
        n = input()
        bff = raw_input().split()
        bff = [int(s) for s in bff]
        max_circle = solver(bff)
        # print max_circle
        print "Case #%d: %d" % (caseNr, len(max_circle))