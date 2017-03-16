#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
import re

class Jumper(object):
    def __init__(self):
        self.i = 0
        self.j = 0
        self.jump_len = 1
        self.path = ''
    
    def jump(self, direction):
        if direction == 'N':
            self.j += self.jump_len
        elif direction == 'S':
            self.j -= self.jump_len
        elif direction == 'W':
            self.i -= self.jump_len
        elif direction == 'E':
            self.i += self.jump_len
        self.path += direction
        self.jump_len += 1
        return self.path
    
    def should_stop(self, direction):
        if direction in 'EW' and abs(self.i - x) < self.jump_len:
            return True
        if direction in 'NS' and abs(self.j - y) < self.jump_len:
            return True
        return False

    def jump_to_region(self, x, y):
        if abs(x) < abs(y):
            directions = ('E' if x > 0 else 'W', 'N' if y > 0 else 'S')
        else:
            directions = ('N' if y > 0 else 'S', 'E' if x > 0 else 'W')
        for direction in directions:
            while True:
                if self.should_stop(direction):
                    break
                self.jump(direction)
                
    def jump1(self, direction):
        opposite = {
            'N': 'S',
            'S': 'N',
            'E': 'W',
            'W': 'E'
        }
        self.jump(opposite[direction])
        self.jump(direction)

    def jump_to_point(self, x, y):
        while x != self.i:
            direction = 'E' if x > self.i else 'W'
            self.jump1(direction)
        while y != self.j:
            direction = 'N' if y > self.j else 'S'
            self.jump1(direction)

def solve(x, y):
    jumper = Jumper()
    #import ipdb; ipdb.set_trace()
    jumper.jump_to_region(x, y)
    jumper.jump_to_point(x, y)
    return jumper.path

if __name__ == '__main__':
    inputdata = sys.stdin
    #inputdata = open('pogotest.txt', 'rt')
    number = next(inputdata).rstrip()
    number = int(number)
    for case in range(number):
        line = next(inputdata)
        x, y = map(int, line.split(' '))
        result = solve(x, y)
        print('Case #{0}: {1}'.format(case+1, result))
