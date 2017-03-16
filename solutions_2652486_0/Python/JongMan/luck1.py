import sys
rl = sys.stdin.readline

t = int(rl())
R, N, M, K = map(int, rl().split())
print 'Case #1:'


cnt = {}
for i in xrange((M-1)**N):
    choice = i
    cards = []
    for j in xrange(N):
        cards.append((choice % (M-1)) + 2)
        choice /= (M-1)
    cards = tuple(sorted(cards))
    cnt[cards] = cnt.get(cards, 0) + 1


possible = {}
for cards in cnt:
    prods = []
    for subset in xrange(2**N):
        prod = 1
        for i in xrange(N):
            if (subset & (2**i)):
                prod *= cards[i]
        prods.append(prod)
    possible[cards] = prods

# for k, v in sorted(cnt.items()):
#     print 'cards', k, 'cnt', v, 'possible', possible[k]

for i in xrange(R):
    nums = map(int, rl().split())
    chance = {cards: 1.0 for cards in cnt}
    for num in nums:
        for cards in cnt:
            chance[cards] *= possible[cards].count(num) / (2.0 ** N)
    max_chance = 0
    ret = [2] * N
    for cards, prob in chance.items():
        if max_chance < prob * cnt[cards]:
            max_chance = prob * cnt[cards]
            ret = cards
    print ''.join(map(str, ret))

            


