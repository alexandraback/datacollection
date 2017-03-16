import itertools

N = 16
J = 50

print("Case #1:")
for _, tup in zip(range(J), itertools.product(['00', '11'], repeat=N // 2 - 1)):
    coin = '1%s1 3 4 5 6 7 8 9 10 11' % (''.join(tup),)
    print(coin)

