from math import sqrt
import random
import time
start_time = time.time()

outfile = open('out/C-large.out', 'w')
outfile.write("Case #1:")

N = 32
J = 500

primes = [2, 3]
for possible_prime in range(5, 10**5):
    for prime in primes:
        if (prime * prime - 1 > possible_prime):
            primes.append(possible_prime)
            break
        if (possible_prime % prime == 0):
            break
    else:
        primes.append(possible_prime)
# 
# print(len(primes))

def get_nontrivial_divisor(n):
    # for i in range(2, int(sqrt(n)) + 1):
    for prime in primes:
        if n % prime == 0:
            return prime
    return -1

jamcoins = []
not_good = 0
for i in range(2**(N-2)):
    if len(jamcoins) == J:
        break
    random_num = random.randint(0, 2**(N-2)-1)
    coin = '1' + str(bin(random_num)[2:].zfill(N-2)) + '1'
    row = "\n" + coin
    for j in range(2, 11):
        coin_in_base_j = int(coin, j)
        divisor = get_nontrivial_divisor(coin_in_base_j)
        if divisor == -1:
            not_good += 1
            break
        row += ' ' + str(divisor)
    else:
        jamcoins.append(coin)
        outfile.write(row)
        # print (len(jamcoins), ":", row)
 
outfile.close()
print("Not good nums:", not_good)
print("--- %s seconds ---" % (time.time() - start_time))
