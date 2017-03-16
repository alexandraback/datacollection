#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    n, = ints()
    CALC.calctill(n)
    return CALC.get(n)

def rev(i):
    res = ''.join(reversed(str(i))).lstrip('0')
    if res:
        return int(res)

class Calc(object):
    def __init__(self):
        self.num2round = {1: 1}
        self.lastround = [1]
        self.lastroundno = 1
    def calctill(self, N):

        while N not in self.num2round:
            round = self.lastroundno + 1
            thisround = []
            for i in self.lastround:
                if (i+1) not in self.num2round:
                    thisround.append(i+1)
                    self.num2round[i+1] = round
                if rev(i) not in self.num2round:
                    r = rev(i)
                    thisround.append(r)
                    self.num2round[r] = round

            self.lastround = thisround
            self.lastroundno = round
    def get(self, i):
        return self.num2round[i]

CALC = Calc()

if __name__ == '__main__':
    main()
