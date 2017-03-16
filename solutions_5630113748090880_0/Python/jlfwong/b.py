"""
Brute force: (2*N-1 choose N) * N log N
Works for small case (19 choose 10 = 92378)

Better: find pairs of possible papers that set up the diagonal, then sort
those.

There can't be more than 2 papers with the same number in the same position.

Can I arbitrarily select which one to be the row and col?

I want to just try all pairs as rows and columns, but that's 2^N (2^(N-1) if
I arbitrarily select the first one to be a row).

1 2 3 4
2 3 4 5
3 5 6 8
4 7 8 9

1 2 3 4
2 3 5 7
3 4 
4 5

If Jacob solved this in 6 minutes, I think I'm missing something. Maybe I don't
need to find the actual matrix at all?

All numbers should occur exactly twice in the diagonal. The one missing a pair
at the diagonal must be the one with the missing pair. Can I do something weird
where I find which numbers have an odd number of matching numbers, then just
sort them?

Seems like that should work
"""
import collections

T = input()

for case_num in xrange(T):
    N = input()

    papers = []
    for i in xrange(2*N-1):
        papers.append(map(int, raw_input().split()))

    diag_order = []

    count = collections.Counter()

    for p in papers:
        count += collections.Counter(p)

    odd_counts = [k for k, v in count.iteritems() if v % 2 == 1]

    ans = ' '.join(map(str, sorted(odd_counts)))

    print 'Case #%d: %s' % (case_num + 1, ans)
