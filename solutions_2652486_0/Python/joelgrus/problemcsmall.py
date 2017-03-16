infile = "C-small-1-attempt0.in"
outfile = "C-small-0.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")

from collections import defaultdict

import math

T = int(lines[0])
R,N,M,K = [int(x) for x in lines[1].split()]
lines = lines[2:]

valid_cards = range(2,M+1)

def ascending(hand):
    for i in range(len(hand) - 1):
        if hand[i+1] < hand[i]:
            return False
    return True

def all_hands_with_n_cards(n):
    if n == 0:
        return [ [] ]
    smaller_hands = all_hands_with_n_cards(n-1)
    return [ hand + [ c ]
             for c in valid_cards
             for hand in smaller_hands
             if ascending( hand + [c] )]

def all_subsets_of_n_cards(n):
    if n == 0:
        return [ [] ]
    smaller_subsets = all_subsets_of_n_cards(n-1)
    with_n = [ ss + [n-1] for ss in smaller_subsets]
    return smaller_subsets + with_n

all_hands = all_hands_with_n_cards(N)
all_subsets = all_subsets_of_n_cards(N)

def sample(hand,subset):
    product = 1
    for i in subset:
        product *= hand[i]
    return product

def likelihood(product,hand):
    return len([s for s in all_subsets
                if sample(hand,s) == product])

def most_likely_hand(products):
    best_hand = None
    best_likelihood = 0
    for hand in all_hands:
        ll = 1
        for product in products:
            ll *= likelihood(product,hand)
        if ll > best_likelihood:
            best_likelihood = ll
            best_hand = hand
    return best_hand, best_likelihood

outf.write("Case #1:" + "\n")
for loop in range(R):
    #print loop
    #print lines
    products = [int(x) for x in lines[0].split()]
    lines = lines[1:]
    best_hand, best_ll = most_likely_hand(products)
    outstr = "".join([str(x) for x in best_hand])
    outf.write(outstr + "\n")

outf.close()
