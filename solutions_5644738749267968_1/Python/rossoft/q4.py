#!/usr/bin/python
import sys
import math


def check_naomi_scores_all(blocks_naomi, blocks_ken):
    """
     Returns true if naomi scores all points
    """
    for i in xrange(len(blocks_naomi)):
        if blocks_naomi[i] < blocks_ken[i]:
            return False
    return True


def play_deceitful_war(n, blocks_naomi, blocks_ken):
    points_naomi = 0

    for i in xrange(n):
        if check_naomi_scores_all(blocks_naomi, blocks_ken):
            #naomi scores all points as all blocks are higher
            points_naomi += len(blocks_naomi)
            return points_naomi

        else:
            #naomi should still be playing Deceitful war
            #ken scores
            min_naomi = blocks_naomi[0]
            max_ken = blocks_ken[-1]

            blocks_naomi.remove(min_naomi)
            blocks_ken.remove(max_ken)

    return points_naomi


def minimum_higher_value(blocks_ken, value):
    for i in xrange(len(blocks_ken)):
        if blocks_ken[i] >= value:
            return blocks_ken[i]

    print "ERROR"
    sys.exit(1)

def play_war(n, blocks_naomi, blocks_ken):
    points_naomi = 0

    for i in xrange(n):
        #naomi should still be playing war
        max_naomi = blocks_naomi[-1]
        max_ken = blocks_ken[-1]
        min_ken = blocks_ken[0]

        blocks_naomi.remove(max_naomi)

        if max_naomi >= max_ken:
            #ken gives the lowest valued one
            points_naomi += 1
            blocks_ken.remove(min_ken)
        else:
            #ken gives the one with inmediately higher cost
            blocks_ken.remove(minimum_higher_value(blocks_ken, max_naomi))

    return points_naomi


def main():
    tests = int(sys.stdin.readline())

    for test in xrange(tests):
        N = int(sys.stdin.readline())
        blocks_naomi = [float(x) for x in sys.stdin.readline().rstrip().split(" ")]
        blocks_ken = [float(x) for x in sys.stdin.readline().rstrip().split(" ")]

        blocks_naomi = sorted(blocks_naomi)
        blocks_ken = sorted(blocks_ken)

        deceitful_points = play_deceitful_war(N, list(blocks_naomi), list(blocks_ken))
        war_points = play_war(N, blocks_naomi, blocks_ken)

        print "Case #%d: %d %d" % (test + 1, deceitful_points, war_points)

main()
