#!/usr/bin/python

import sys
import functools

def minTwoJudgeScores(scores):
    mi = 0
    for i in xrange(1, len(scores)):
        if scores[i] < scores[mi]:
            mi = i

    scores = scores[:mi] + scores[mi+1:]

    mi2 = 0
    for i in xrange(1, len(scores)):
        if scores[i] < scores[mi2]:
            mi2 = i

    if mi2 >= mi:
        mi2 += 1
    return mi, mi2

def findMax(scores):
    max_i = 0
    for i in xrange(1, len(scores)):
        if scores[i] is not None and (scores[max_i] is None or scores[i] > scores[max_i]):
            max_i = i
    return max_i


def findMin(judge_scores, X, mi, mi2, i):
    if i == mi:
        min_ = mi2
    else:
        min_ = mi

    answer = 0.5 * (float(judge_scores[min_] - judge_scores[i]) / X + 1)

    #print min_, i, X, answer, (judge_scores[min_] - judge_scores[i])

    return answer

N = int(sys.stdin.readline())
for test_case, test_case_str in enumerate(sys.stdin.readlines(), 1):
    judge_scores = map(int, test_case_str.strip().split())[1:]
    X = sum(judge_scores)

    mi, mi2     = minTwoJudgeScores(judge_scores)
    max_i       = findMax(judge_scores)

    differences = [ judge_scores[max_i] - score if score is not None else None for score in judge_scores ]
    yi_matches  = [ float(diff) / X if diff is not None else None for diff in differences ]
    yi_left     = 1 - sum([y for y in yi_matches if y is not None])

    while yi_left < 0:
        judge_scores[max_i] = None
        max_i               = findMax(judge_scores)
        differences         = [ judge_scores[max_i] - score if score is not None else None for score in judge_scores ]
        yi_matches          = [ float(diff) / X if diff is not None else None for diff in differences ]
        yi_left             = 1 - sum([y for y in yi_matches if y is not None])

    #print 'yi', yi_left

    #print 'max_i', max_i
    #print yi_matches

    not_none = [y for y in yi_matches if y is not None]

    solveCase = functools.partial(findMin, judge_scores, X, mi, mi2)
    solved = [ (yi + yi_left / len(not_none)) * 100 if yi is not None else 0 for yi in yi_matches]


    #print X, mi, mi2

    print "Case #%d: %s" % (test_case, ' '.join(map(str, solved)))
