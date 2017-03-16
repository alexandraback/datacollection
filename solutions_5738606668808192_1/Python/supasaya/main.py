import math
import string
import gc


def prime(num):
    for i in range(2,100):
        if (num % i) == 0:
            return i
    return -1

jamcoin = '10000000000000000000000000000000'
n = 500
print "Case #1:"
while n > 0:
    jamcoin = long(jamcoin, 2) + 1
    jamcoin = str(bin(jamcoin))[2:]
    while jamcoin[-1] == '0':
        jamcoin = long(jamcoin, 2) + 1
        jamcoin = str(bin(jamcoin))[2:]
    pp = True
    list = []
    for i in range(2,11):
        ans = prime(long(jamcoin,i))
        if ans == -1:
            pp = False
            break
        else:
            list.append(ans)
    if pp:
        n -= 1
        print jamcoin,
        for i in range(0,9):
            print list[i],
        print
    gc.collect()