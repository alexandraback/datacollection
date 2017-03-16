from math import sqrt
import time
start_time = time.time()

outfile = open('out/C-small.out', 'w')
outfile.write("Case #1:")

N = 16
J = 50


def get_nontrivial_divisor(n):
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return i
    return -1

jamcoins = 0
for i in range(2**(N-2)):
    if jamcoins == J:
        break
    coin = '1' + str(bin(i)[2:].zfill(N-2)) + '1'
    row = "\n" + coin
    for j in range(2, 11):
        coin_in_base_j = int(coin, j)
        divisor = get_nontrivial_divisor(coin_in_base_j)
        if divisor == -1:
            break
        row += ' ' + str(divisor)
    else:
        jamcoins += 1
        outfile.write(row)
        # print (row)

outfile.close()
print("--- %s seconds ---" % (time.time() - start_time))
