# -*- coding: UTF-8 -*-

import sys


class FileParser:
    """Read numbers/strings from file (or stdin by default), one line by one.

    Example:
        inputfile = FileParser()
        # Read a line of 5 integers
        R, S, U, P, M = inputfile.readIntegers()
        inputfile.close()
    """

    def __init__(self, filepath=None):
        if filepath is None:
            self.fd = sys.stdin
        else:
            self.fd = open(filepath)

    def read_string(self):
        return self.fd.readline().rstrip()

    def read_words(self):
        return [x for x in self.read_string().split()]

    def read_int(self):
        return int(self.fd.readline())

    def read_integers(self):
        return [int(x) for x in self.fd.readline().split()]

    def read_float(self):
        return float(self.fd.readline())

    def read_floats(self):
        return [float(x) for x in self.fd.readline().split()]

    def close(self):
        if self.fd is not sys.stdin:
            self.fd.close()
        self.fd = None
