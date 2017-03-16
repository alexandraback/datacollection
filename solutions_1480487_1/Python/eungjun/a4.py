# -*- coding: utf-8 -*- 
import os, sys, copy, time, itertools

def solve(line):
    scores = map(float, line.split())
    scores.pop(0)
    scores_sum = sum(scores)
    n = len(scores)
    result = [0] * n

    for i in xrange(len(scores)):
        done = False

        remains = scores[:i] + scores[i + 1:]
        while not done:
            m = (sum(remains) - len(remains) * scores[i] + scores_sum) / ((len(remains) + 1) * scores_sum)

            if m < 0:
                result[i] = 0
                done = True
            else:
                # print sum(remains), (1 - m) * scores_sum, len(remains)
                avr = (sum(remains) + (1 - m) * scores_sum) / len(remains)
                if avr < max(remains):
                    remains.pop(remains.index(max(remains)))
                    # remains = [x for x in remains if x <= mid]
                    done = False
                else:
                    result[i] = m * 100
                    done = True
                    # print avr

    return result


lines = sys.stdin.read().split('\n')
lines.pop()
lines.pop(0)

case = 0
while lines:
    case += 1
    line = lines.pop(0)

    # print line
    print 'Case #%d: %s' % (case, ' '.join(map(str, solve(line))))
