import math

N = 16
J = 50

outfile = open('out.txt', 'w')
outfile.write('Case #1:\n')

jamcoin_mask = (1 << (N-1)) | 1
jamcoins = [[0]*11] * J

k = 0
for i in xrange(N-2): 
  k <<= 1
  k |= 1

index = 0
k2 = 0
while k2 <= k and index < J:
  coin = jamcoin_mask | (k2 << 1)

  isjamcoin = True
  for base in xrange(2, 11):
    value = 0
    coin2 = coin

    power = 0
    while coin2 > 0:
      value += (coin2 & 1) * (base**power)

      coin2 >>= 1
      power += 1

    isprime = True
    for i in xrange(2, 5000): 
      if (value % i) == 0:
        isprime = False
        jamcoins[index][base] = i
        break

    if isprime:
      break

    if base == 10:
      outfile.write(str(value))
      for b in xrange(2, 11):
        outfile.write(' ' + str(jamcoins[index][b]))
      outfile.write('\n')
      index += 1

  k2 += 1

