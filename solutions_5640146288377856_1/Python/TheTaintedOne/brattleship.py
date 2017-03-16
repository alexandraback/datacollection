import sys
import itertools

lines = sys.stdin.readlines()

ntests = int(lines[0])


def computeHits(W, remains):
    g1 = W - remains # guarranteed hits
    g2 = remains
    if remains>0:
        g2 += 1
    return g1 + g2


curr = 1
for t in range(1, ntests+1):
    R, C, W = [int(x) for x in lines[curr].split()]
    # print R, C, W

    # sample case
    guess = (C/W)*R
    remains = C%W
    # print guesses, remains

    # guess2 = W-remains; # guarranteed hits

    # # print guess, guess2

    # guess += guess2
    # guess += remains
    # if remains>0:
    #     guess += 1
    # print guess, remains
    # print computeHits(W, remains), computeHits(W,W-1)
    guess += computeHits(W, remains)


    guess -= 1 # minus the initial hit

    curr += 1
    print "Case #"+ str(t) + ": " + str(guess)
