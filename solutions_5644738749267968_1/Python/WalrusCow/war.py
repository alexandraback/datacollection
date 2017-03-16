import sys

# They only have 5 decimal places
DELTA = 1e-6

def naomiDeceit(n, k):
    ''' Decide which block Naomi will play, for deceit.  '''

    kBig = k[-1] # Ken's largest block
    # Play the lowest that is larger than Ken's lowest, but claim
    # that it is bigger than Ken's biggest
    kLow = k[0]
    for i, b in enumerate(n):
        if b > kLow:
            say = kBig + DELTA
            break
    # No big enough block to win: play smallest block,
    # but claim it is just less than Ken's biggest block
    if b < kLow:
        b = n[0]
        i = 0
        say = kBig - DELTA
    n.pop(i)
    return b, say

def naomiPlay(n, k):
    ''' For normal war, naomi can just play any block... doesn't matter. '''
    b = n.pop()
    return b, b

def kenPlay(block, k):
    ''' Decide which block Ken will play. '''
    for i, b in enumerate(k):
        if b > block: break
    if b < block:
        # Nothing high enough: play the lowest one
        b = k[0]
        i = 0
    k.pop(i)
    return b

def war(nBlocks, kBlocks, nPlay, kPlay):
    ''' Play war with block sets n, k and given strategies. '''
    naomiWins = 0
    for _ in range(len(nBlocks)):
        nBlock, nSay = nPlay(nBlocks, kBlocks)
        kBlock = kPlay(nSay, kBlocks)
        if nBlock > kBlock:
            naomiWins += 1
    return naomiWins

def main(n):
    ''' Read and perform n test cases. '''

    for i in range(1, n+1):
        # Read the number of blocks
        numBlocks = int(sys.stdin.readline())

        # Read blocks for Naomi and Ken... we want them sorted, always
        naomi = sorted(list(map(float, sys.stdin.readline().split())))
        ken = sorted(list(map(float, sys.stdin.readline().split())))

        # Get scores for deceitful war and war
        decScore = war(naomi[::], ken[::], naomiDeceit, kenPlay)
        warScore = war(naomi, ken, naomiPlay, kenPlay)
        print('Case #{}: {} {}'.format(i, decScore, warScore))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
