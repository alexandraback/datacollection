# -*- coding: utf-8 -*-

# start of common segment

import sys
import logging
logging.basicConfig(stream=sys.stderr, level=logging.WARNING)
logger = logging.getLogger(__name__)

from ms import Board

with open(sys.argv[1].strip()) as fp:
    INPUT_LINES = map(str.strip, fp.readlines())

# end of common segment

NCASES = int(INPUT_LINES[0])
del INPUT_LINES[0]

for CASE_N in xrange(1, NCASES+1):
    print("Case #%d:" % CASE_N)
    R, C, M = map(float, INPUT_LINES[0].split())
    del INPUT_LINES[0]

    board = Board(R, C, M)
    ret = board.solve()

    if ret:
        print(board)
    else:
        print("Impossible")
