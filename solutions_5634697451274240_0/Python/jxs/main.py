#! /usr/bin/env python3

T = int(input())

for case_nr in range(1,T+1):
    pile = [ (True if b == '+' else False) for b in input() ]

    # Ensure that all pancakes have the same orientation (starting from the top)
    flip_count = 0
    last = pile[0]
    for p in pile[1:]:
        if not p == last:
            flip_count += 1
            last = p

    # if all pancakes are upside down, perform one last gigantic flip move
    if not last: flip_count += 1

    print("Case #{}: {}".format(case_nr, flip_count))

