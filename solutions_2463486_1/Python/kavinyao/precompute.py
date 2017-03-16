# -*- coding:utf-8 -*-

import sys
import math
from itertools import ifilter, imap

"""
Fair and Square numbers precomputer.
"""

is_palindrome = lambda n: n == int(str(n)[::-1])

def precompute(limit):
    upper_bound = int(math.ceil(math.sqrt(limit)))
    return ifilter(is_palindrome, imap(lambda x: x*x, ifilter(is_palindrome, xrange(1, upper_bound))))

if __name__ == '__main__':
    limit = int(sys.argv[1])
    print list(precompute(limit))
