# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

def iwin_dw(my_cards, _his_cards):

    if my_cards[-1] < _his_cards[0]: 
        logger.debug("Shortcut, lost all")
        return 0

    if my_cards[0] > _his_cards[-1]: 
        logger.debug("Shortcut, win all")
        return len(my_cards)

    # We modify `his_cards`, so copy it first
    his_cards = list(_his_cards)

    iwon = 0
    for _, my_point in enumerate(my_cards):
        # take my card from the smallest
        if my_point > his_cards[0]:
            # use that card and win another deck
            del his_cards[0]
            iwon += 1
            continue
        
        # can't win with it, bait his largest one
        del his_cards[-1]

    return iwon


# ==========================================================================================
# ==========================================================================================
# ==========================================================================================
# ==========================================================================================
# ==========================================================================================
# ==========================================================================================

def idx_larger_than(haystack, needle):
    """Takes an sorted list, and find the index of 
    the first value larger than needle.

    Returns natural number if found, None if not found (all smaller than needle)"""

    l, r = 0, len(haystack) - 1
    m = (l + r) / 2

    if haystack[0] > needle:
        logger.debug("Searching %.5f in his deck, shortcut 0(%.5f):" % (needle, haystack[0]))
        return 0

    if haystack[r] < needle: 
        logger.debug("Searching %.5f in his deck, shortcut None(max = %.5f):" % (needle, haystack[-1]))
        return None

    while m > l:
        if haystack[m] > needle:
            r = m
        elif haystack[m] < needle:
            l = m
        else:
            raise Exception("WTF, draw game, blame Google")

        m = (l + r) / 2

    logger.debug("Searching %.5f in his deck, [%d]%.5f - *[%d]%.5f" % (needle, l, haystack[l], r, haystack[r]))
    return r

def iwin_w(my_cards, _his_cards):
    iwon = 0
    his_cards = list(_his_cards)

    for _, my_point in enumerate(my_cards):
        his_idx = idx_larger_than(his_cards, my_point)
        if his_idx is None:
            # he can't win, so plays the smallest
            del his_cards[0]
            logger.debug("After dropping least card: %s" % his_cards)
            iwon += 1
        else:
            # he plays that card, I lost
            del his_cards[his_idx]
            logger.debug("Cards remaining: %s" % his_cards)

    return iwon
