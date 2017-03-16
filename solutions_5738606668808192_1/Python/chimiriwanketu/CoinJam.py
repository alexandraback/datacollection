__author__ = 'Owen'
import math

def toDecimal(number, base):
    num = 0
    for i in range(len(number)):
        if number[len(number) - i - 1] == "1":
            num += (base**i)

    return num

def divisor(n):
    i = 2
    while i <= 1000000:
        if n % i == 0:
            return i
        i += 1

    return 1;

def CoinJam(number, call):
    if call == 30:
        number += "1"
        sol = number
        for n in range(2, 11):
            k = toDecimal(number, n)
            m = divisor(k)
            if m == 1:
                break
            sol += " "+str(m)

        if m != 1:
            print sol

    else:
        CoinJam(number + "0", call + 1)
        CoinJam(number + "1", call + 1)


CoinJam("1", 0)

