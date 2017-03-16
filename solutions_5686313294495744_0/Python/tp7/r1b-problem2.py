# -*- coding: utf-8 -*-
import fileinput
import collections
import itertools


# def can_be_fake(pair, pairs_list):


class Pair(object):
    def __init__(self, pair):
        self.left = pair[0]
        self.right = pair[1]
        self.fake = False



    def __repr__(self):
        return "%s %s   %s" % (self.left, self.right, self.fake)



def solve(pairs_list):
    pairs_list = [Pair(p) for p in pairs_list]

    fakes_count = 0
    for pair in pairs_list:
        seen_first, seen_second = False, False
        for candidate in pairs_list:
            if pair is candidate or candidate.fake:
                continue

            if pair.right == candidate.right:
                seen_second = True
            elif pair.left == candidate.left:
                seen_first = True

            if seen_first and seen_second:
                pair.fake = True
                fakes_count += 1
                break

    return fakes_count


def run():
    in_stream = fileinput.input()
    cases_count = int(in_stream.readline())

    for case in xrange(cases_count):
        input_pairs = []
        pairs_count = int(in_stream.readline())
        for _ in xrange(pairs_count):
            input_pairs.append(tuple(in_stream.readline().strip().split()))

        answer = solve(input_pairs)
        print("Case #{0}: {1}".format(case + 1, answer))


if __name__ == "__main__":
    # print(solve([
    #     ("HYDROCARBON", "COMBUSTION"),
    #     ("HYDROCARBON", "BEHAVIOR"),
    #     ("QUAIL", "COMBUSTION"),
    #     ("QUAIL", "BEHAVIOR"),
    # ]))
    run()
