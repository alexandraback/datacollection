#!/usr/bin/env python

import fileinput

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2013-04-12"

class Problem:
    __debug = False

    def resolve(self):
        disks = 0
        radiuos = self.__radio
        while self.__mili >= 0:
            self.__mili -= (((radiuos + 1) ** 2) - ((radiuos) ** 2))
            radiuos += 2

            if self.__mili >= 0:
                disks += 1

        return disks

    def __init__(self, inMainRadio, inMililiters):
        self.__radio = inMainRadio
        self.__mili = inMililiters

        if self.__debug:
            print "MainRadio: %s Mililiters: %s" % (self.__radio, self.__mili) 

if __name__ == "__main__":
    lines = [line.replace('\n', '') for line in fileinput.input()]

    for line in xrange(1, int(lines[0]) + 1):
        lineInfo = map(int, lines[line].split())
        print "Case #%d: %s" % (line, Problem(lineInfo[0], lineInfo[1]).resolve())
