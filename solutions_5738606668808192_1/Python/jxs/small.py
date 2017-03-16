#! /usr/bin/env python3

T = int(input())
N, J = [ int(i) for i in input().split() ]

print("Case #1:")

basis = {}
for b in range(2,11):
    basis[b] = [ b**i for i in reversed(range(N)) ]

num_coins = 0
bit_count = 0

while num_coins < J:

    jamcoin = [ 1 if i == '1' else 0 for i in bin(bit_count)[2:] ]
    jamcoin = [0] * ((N-2) - len(jamcoin)) + jamcoin
    jamcoin = [1] + jamcoin + [1]

    valid = True
    divs = []

    for b in range(2,11):
        val = sum([ (basis[b][i] * jamcoin[i]) for i in range(N) ])

        divisible = False
        for dv in range(2,1000):
            if val % dv == 0:
                divs.append(dv)
                divisible = True
                break

        if not divisible: valid = False


    if valid:
        num_coins += 1
        print("{} {}".format(''.join([ str(s) for s in jamcoin ]), ' '.join([ str(s) for s in divs ])))

    bit_count +=1
