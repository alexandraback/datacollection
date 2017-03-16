#!/usr/bin/env python

import itertools, fileinput

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2013-05-12"

class Problem:
    __debug = False
    __vowels = set(['a', 'e', 'i', 'o', 'u'])

    def __getConsonants(self, inStr):
        maxCons = 0
        cons = 0
        for char in inStr:
            if char in self.__vowels:
                if cons > maxCons:
                    maxCons = cons
                cons = 0
            else:
                cons += 1

        if cons > maxCons:
            return cons

        return maxCons

    def resolve(self):
        substrings = [ self.__line[ index : index + length ] for index in range( len( self.__line )) for length in range( self.__n, len( self.__line ) - index + 1 ) ]
        numSubStr = 0
        for string in substrings:
            if self.__getConsonants(string) >= self.__n:
                numSubStr += 1

        return numSubStr

    def __init__(self, inLine, inN):
        self.__line = inLine
        self.__n = int(inN)

        if self.__debug:
            print "Line: %s" % (self.__line) 
            print "N: %s" % (self.__n) 

if __name__ == "__main__":
    lines = [line.replace('\n', '') for line in fileinput.input()]

    for problem in range(int(lines[0])):
        print "Case #%d: %s" % (problem + 1, Problem(*lines[problem + 1].split()).resolve())
