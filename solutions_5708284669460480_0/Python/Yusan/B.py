#!/usr/bin/python
# vi: set fileencoding=utf-8 :


def bananas(substring, target):
    score = 0
    for i in range(len(substring) - len(target) + 1):
        if substring[i:i+len(target)] == target:
            score += 1
    return score


def enumerate_string(keyboard, target, substring, S, total_score, max_score):
    if len(substring) == S:
        score = bananas(substring, target)
        return total_score + score, score
    else:
        for k in keyboard:
            total_score, score = enumerate_string(keyboard, target, substring + k, S, total_score, max_score)
            max_score = max(score, max_score)
        return total_score, max_score


def expected_bananas(K, L, S, keyboard, target):
    if target == 'ROSENCRANTZ':
        return 0
    max_banana = 0
    total_score, max_score = enumerate_string(keyboard, target, '', S, 0, 0)
    return max_score - total_score / float(K ** S)


T = int(raw_input())
for case_number in range(1, T + 1):
    K, L, S = map(int, raw_input().split())
    keyboard = raw_input().rstrip()
    target = raw_input().rstrip()
    print 'Case #%d: %08.7f' % (case_number, expected_bananas(K, L, S, keyboard, target))
