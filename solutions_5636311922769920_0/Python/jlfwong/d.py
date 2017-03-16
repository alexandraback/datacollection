"""
T: # test cases
K: length of original sequence
C: generation #
S: # of tiles allowed to be uncovered

for small, K=S

I think, for small, we can just look at every K^(C-1)'th tile. If any of them
are G, then the original sequence has G, otherwise it doesn't.

This works because G always replicated to K G's.

for large, 1 <= S <= K, which is sometimes not impossible, so that solution
won't work.

Our task is phrased as finding out if at least one G occurs in the original
sequence. Put another way, our task is deciding whether or not the original
sequence consists entirely of L's.

If the entire original sequence consists of L's, then the artwork is guaranteed
to contain no G's. Conversely, if the final artwork is entirely L's, then the
original sequence must consist entirely of L's.

Since for any K, there are 2^K possible sequences, we need at least log(2^K)
bits of information... doesn't that mean we need to uncover K tiles? That would
suggest we always need S >= K for the solution to not be IMPOSSIBLE, but
I doubt that's the solution.... Perhaps uncovering a single tile provides more
than one bit of information though.

In the example:
    
    K=2, C=3, S=1
    Original sequence GG: GGGGGGGG
    Original sequence GL: GGGGGGGL
    Original sequence LG: LGGGGGGG
    Original sequence LL: LLLLLLLL

In this case, we need only look at tile #2, since it uniquely predicts whether
or not the original sequence was LL. This must mean that uncovering tile #2
provides TWO bits of information. I'm unsure of the lower bound on S then.

I see now -- the answer isn't always log K because we don't need to uniquely
identify a solution, we only need to know whether it is or is not one specific
solution. In the above case, if we look at tile #2, we don't know which of the
4 original sequences it was, we just know for certain that it's not LL. I don't
know how many bits of information that represents.

If we've found any G's, we know the original sequence contained a G. If we've
uncovered L's so far, it's possible that the entire original sequence consists
entirely of L's. So the question becomes "what is the maximum number of L's
that can we may uncovered in a sequence containing a G if we select
optimally?". That (plus 1) will be the lower bound for S without being
impossible.

In the example:
    
    K=2, C=3, S=1
    Original sequence GG: GGGGGGGG
    Original sequence GL: GGGGGGGL
    Original sequence LG: LGGGGGGG
    Original sequence LL: LLLLLLLL

Examining the second tile logically gives 2 pieces of information if it's an L.

If tile #2 is an L, it means that tile #1 must also be an L because it must be
an expansion of the original sequence (otherwise it would've had to be a G).
Since it's a reproduction of the original sequence, this means that the
original sequence MUST be LL.

Interestingly, discovering tile #1 is an L doesn't give us any more insight
into what any of the other tiles are. Examing the second tile will always give
us more information. If we uncover a G, we're done. If we uncover an L, we know
that the first two tiles of the original sequence must be LL.

Our goal is the figure out the minimal number of L tiles we need to uncover to
deduce that the original sequence consists entirely of L's. In the example
above, this is 1.

We can generalize this approach to get an upper bound on the number of needed
tiles to K/2. To do this, we always select a tile where an L would tell us the
location of TWO of the L tiles in the original sequence. If we select tile #2
of block #1, an L implies that the first TWO tiles were L. If we select tile #4
of block #3, an L implies that both original tile #3 was an L and original tile
#4 was an L. (Blocks are the final sequence divided into blocks of length
K^(C-1)). For C = 1, the lower bound is certainly K, because we must examine
the whole sequence.

Can we derive information about more than 2 tiles from the original sequence?
Or can we prove that this is the maximum amount of information we can extract
from a single tile?

LLL

LLL LLL LLL
^     ^
A'    B'

LLL LLL LLL . LLL LLL LLL . LLL LLL LLL
 ^                     ^
 A                     B

If position A is L, what does it imply? In the original sequence, both tile #1
and tile #2 must be L. tile #3 could still be a G.

If position B is L, what does it imply? In the original sequence, both tile #6
in the intermediate is L and that tile #2 in the original sequence is L. If
tile #6 in the intermediate is L, then (???) getting confused here.

Let's say L[i][j] is true if the tile j in the artwork at generation #i is L.

L[i-1][floor(j / K)] && L[0][j % K] <-> L[i][j]

which conversely means:

L[i][j] -> L[0][j % K]
L[i][j] -> L[i-1][floor(j / K)]

How do you apply this recursively? @_@

Let's try a simple case from before:

    K=2, C=3, S=1
    Original sequence GG: GGGGGGGG
    Original sequence GL: GGGGGGGL
    Original sequence LG: LGGGGGGG
    Original sequence LL: LLLLLLLL

L[2][1] = L[2-1][floor(1 / 2)] && L[0][1 % 2]
        = L[1][0] && L[0][1]
        = (L[0][0] && L[0][0]) && L[0][1]
        = L[0][0] && L[0][1]

We'd normally have to prove this in both directions, but we really only care
about the implication if L[2][1] is true. We don't care if L[0][0] or L[0][1]
being false implies that L[2][1] is false.

Can I solve this with a graph of implications, then figure out the minimum
number of to select from L[C] that imply alll of L[0]?

The space requirement for that would be O(C * K^C) which seems too big... There
should be some property of symmetry here of some sort though, right?

Maybe we can do it bottom up? This is starting to kind of seem like a minimum
cover problem.

LLL

LLL LLL LLL

L[1][0] -> L[0][0]
L[1][1] -> L[0][0] && L[0][1]
L[1][2] -> L[0][0] && L[0][2]
L[1][3] -> L[0][1] && L[0][0]
L[1][4] -> L[0][1] && L[0][1]
L[1][5] -> L[0][1] && L[0][2]
L[1][6] -> L[0][2] && L[0][0]
L[1][7] -> L[0][2] && L[0][1]
L[1][8] -> L[0][2] && L[0][2]

It's interesting to note that 3 of these are strictly worse to examine than the
others. Also interesting to note that none of these provide sufficient
informatino by themselves. You must select at least 2 of these to determine if
the original sequence contains any gold.


K=N, C=1, minimum S=K
K=3, C=2, minimum S=2

LL
LL LL
LL LL . LL LL

L[1][0] -> L[0][0] && L[0][0]
L[1][1] -> L[0][0] && L[0][1]
L[1][2] -> L[0][1] && L[0][0]
L[1][3] -> L[0][1] && L[0][1]

L[2][0] -> L[1][0] && L[0][0]
        -> L[0][0]
L[2][1] -> L[1][0] && L[0][1]
        -> L[0][0] && L[0][1]
L[2][2] -> L[1][1] && L[0][0]
        -> L[0][0] && L[0][1] && L[0][0]
        -> L[0][0] && L[0][1]
L[2][3] -> L[1][1] && L[0][0]
        -> L[0][0] && L[0][1]
L[2][4] -> L[1][2] && L[0][0]

This implication tree *seems* like it means that you can determine that THREE
of the original tiles are L based on some L[2][i]. I suspect you can determine
FOUR based on some L[3][i] then, or more generally N of the original tiles
based on L[N+1][i]... but that can't be quite right because there's an upper
bound of K tiles being revealed. That upper bound comes from the inabilityt to
combine information from the previous level in a way that doesn't overlap.

It seems like it should be possible to combine the information from a previous
level to always obtain information about the one additional tile as i increases
though.

If that's true, then I believe the lower bound on S is ceil(K/C). The challenge
then becomes how to select those tiles. It seems like I should be able to
arbitrarily select tiles to obtain information about.

So which tile to I examine in the final artwork to determine whether all of the
first C tiles in the original artwork are L?

Let's try K=7 C=3.

For which j is L[1][j] only true if L[0][0] and L[0][1]?
L[1][1]

For which j is L[2][j] only true if L[1][1] and L[0][2]?

We have a formula here.

floor(j/K) = 1, j % K = 2

so j = K + 2

L[2][9] = L[i-1][floor(9 / 7)] && L[0][9 % 7]
        = L[1][1] && L[0][2]

Woohoo!
"""

import math

T = input()

for case_num in xrange(T):
    K, C, S = map(int, raw_input().split())

    needed = max(1, int(math.ceil(1.0 * K / C) + 0.1))

    if S < needed:
        ans = 'IMPOSSIBLE'
    else:
        ans = []
        for block_start in xrange(0, K, C):
            cur = block_start
            for offset in xrange(1, C):
                cur = cur * K + ((block_start + offset) % K)

            ans.append(cur + 1)   # answer is 1-based

        ans = ' '.join(map(str, ans))

    print 'Case #%d: %s' % (case_num + 1, ans)
