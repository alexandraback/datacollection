# -*- coding: utf-8 -*-

# start of common segment

import sys
import logging
logging.basicConfig(stream=sys.stderr, level=logging.INFO)
logger = logging.getLogger(__name__)

from brain import iwin_w, iwin_dw

with open(sys.argv[1].strip()) as fp:
    INPUT_LINES = map(str.strip, fp.readlines())

# end of common segment

NCASES = int(INPUT_LINES[0])
del INPUT_LINES[0]

for CASE_N in xrange(1, NCASES+1):
    
    deck_len = float(INPUT_LINES[0].strip())
    my_cards = map(float, INPUT_LINES[1].split())
    his_cards = map(float, INPUT_LINES[2].split())
    del INPUT_LINES[:3]

    my_cards.sort()
    his_cards.sort()

    logger.debug("Comparing \n\tmy card: %s\n\this card: %s" % (my_cards, his_cards))

    print("Case #%d: %d %d" % (
        CASE_N, 
        iwin_dw(my_cards, his_cards),
        iwin_w(my_cards, his_cards)
    ))
