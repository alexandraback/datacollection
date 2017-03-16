#!/bin/env python

'''
Created on 10.05.2015

@author: Dennis Nienhüser <earthwings@gentoo.org>
'''

import sys
import math
from collections import Counter


def vectorize(line):
    items = line.strip().split(sep=' ')
    for index, item in enumerate(items):
        items[index] = int(item)
    return items


if __name__ == "__main__":
    inputFile = open(sys.argv[1], 'r')
    problems = int(inputFile.readline())
    for problemIndex in range(problems):
        problem = vectorize(inputFile.readline())
        s = problem[2]
        keyboardString = inputFile.readline().strip()
        keyboard = Counter(keyboardString)
        word = inputFile.readline().strip()
        for key in keyboard.keys():
            keyboard[key] = keyboard[key] / len(keyboardString)

        t = len(word)
        p = 1.0
        for character in word:
            p *= keyboard[character] if character in keyboard else 0.0

        doubled = word + word
        r = doubled.index(word, 1)

        expectedWords = (1+(s-t))*p
        maximumWords = 0 if p <= 0 else 1+math.floor((s-t)/r)
        bananas = maximumWords - expectedWords

        print('Case #' + str(problemIndex + 1) + ": " + str(bananas))
