#!/usr/bin/env python

import fileinput

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2013-05-12"

class Problem:
    __debug = False

    def resolve(self):
        movements = []

        if self.__target[0] > 0:
            movements += 'WE' * self.__target[0]
        else:
            movements += 'EW' * abs(self.__target[0])

        if self.__target[1] > 0:
            movements += 'SN' * self.__target[1]
        else:
            movements += 'NS' * abs(self.__target[1])

        return ''.join(movements)

    def __init__(self, inTargetPos):
        self.__target = inTargetPos

        if self.__debug:
            print "Target: %s" % (self.__target) 

if __name__ == "__main__":
    lines = [line.replace('\n', '') for line in fileinput.input()]

    for problem in range(int(lines[0])):
        print "Case #%d: %s" % (problem + 1, Problem(map(int, lines[problem + 1].split())).resolve())
