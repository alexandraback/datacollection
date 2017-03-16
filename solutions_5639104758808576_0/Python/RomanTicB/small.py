#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve(cipher):
    _sum_audience = 0
    _total_friends = 0

    au_total, au_each = cipher.split(" ")
    for shyness, audience in enumerate(au_each):
        shyness = int(shyness)
        audience = int(audience)

        if _sum_audience < shyness and audience:
            _needed_friend = shyness - _sum_audience
            _total_friends += _needed_friend
            _sum_audience += audience + _needed_friend
        else:
            _sum_audience += audience
    return _total_friends

if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        cipher = raw_input()
        print("Case #%i: %s" % (caseNr, solve(cipher)))