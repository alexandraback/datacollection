"""
My initial thought was find the longest cycle, but I don't think that works.

I think the following is valid:

    1 <-> 2 <- 3

Even though 1 is not BFF's with 3, and 3 is not BFF's with 1. This isn't
a cycle. What is this?

Any 2-cycle can be trivially added to the circle if the circle is *not*
a cycle.

Maybe it's the biggest cycle *OR* the sum of the longest paths ending in
a 2-cycle (since they can all be used).
"""

import collections

T = input()

for case_num in xrange(T):
    N = input()
    F = map(int, raw_input().split())

    longest_cycle = 0
    longest_path_for_2_cycle = collections.defaultdict(int)

    for start in xrange(N):
        seen = set()

        last = None
        cur = start
        ends_in_2_cycle = False
        while cur not in seen:
            seen.add(cur)
            nxt = F[cur] - 1

            if nxt == last:
                longest_path_for_2_cycle[(cur, last)] = max(
                    longest_path_for_2_cycle[(cur, last)],
                    len(seen))

            last = cur
            cur = nxt

        if cur == start:
            longest_cycle = max(longest_cycle, len(seen))

    two_cycle_score = 0
    two_cycles_seen = set()

    for (a, b), v in longest_path_for_2_cycle.iteritems():
        two_cycle_score += v

        if frozenset([a, b]) in two_cycles_seen:
            two_cycle_score -= 2
        else:
            two_cycles_seen.add(frozenset([a, b]))

    ans = max(longest_cycle, two_cycle_score)

    print 'Case #%d: %s' % (case_num + 1, ans)
