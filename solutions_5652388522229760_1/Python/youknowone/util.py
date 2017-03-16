
DEBUG = False

import sys

def debug(*args):
    if DEBUG:
        print ' '.join(map(str, args))

def int_input():
    text = raw_input()
    return int(text)

def float_input():
    text = raw_input()
    return int(text)

def list_input(size=None):
    text = raw_input()
    str_values = text.split(' ')
    if size is not None:
        assert len(str_values) == size
    return str_values

def intlist_input(size=None):
    return map(int, list_input(size))

def floatlist_input(size=None):
    return map(float, list_input(size))

def loop(count, func):
    for x in xrange(0, count):
        func(x)

def print_case(count, fmt, *args):
    prefix = 'Case #{}:'.format(count + 1)
    if len(args):
        print prefix, fmt % args
    else:
        print prefix, fmt

class Plain(object):
    def __init__(self, size, init=None):
        self.size = size
        self.data = [init] * (self.size[0] * self.size[1])

    def __getitem__(self, coord):
        r, c = coord
        index = r * self.size[1] + c
        return self.data[index]

    def __setitem__(self, coord, item):
        r, c = coord
        index = r * self.size[1] + c
        self.data[index] = item

    def debug(self):
        debug('Plain {}x{}'.format(self.size[0], self.size[1]))
        for r in xrange(0, self.size[0]):
            row = [self[r, c] for c in xrange(0, self.size[1])]
            debug(row)
