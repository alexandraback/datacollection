#!/usr/bin/python

import sys

def case(levels):
    level_stars = [2]*len(levels)
    stars = 0
    games = 0
    while levels:
        best_stars = 0
        best_level = None
        for i, lev in enumerate(levels):
            for j, s in enumerate(lev):
                if stars >= s:
                    add = min(level_stars[i], j + 1)
                    if add > best_stars:
                        best_level = i
                        best_stars = add

        if best_level is None:
            return 'Too Bad'
        else:
            #print >> sys.stderr, ">>", best_level, best_stars
            level_stars[best_level] -= best_stars
            if level_stars[best_level] == 0:
                del level_stars[best_level]
                del levels[best_level]
            stars += best_stars
            games += 1

    return games

def main():
    T = int(sys.stdin.readline())
    for x in xrange(1, T+1):
        N = int(sys.stdin.readline())
        levels = []
        for i in xrange(N):
            levels.append(map(int, sys.stdin.readline().split()))
        print "Case #%d: %s" % (x, case(levels))

main()
