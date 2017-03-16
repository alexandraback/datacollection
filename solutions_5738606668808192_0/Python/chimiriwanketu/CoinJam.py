__author__ = 'Owen'
import math

def toDecimal(number, base):
    num = 0
    for i in range(len(number)):
        if number[len(number) - i - 1] == "1":
            num += (base**i)

    return num

def divisor(n):
    for i in range(2, int(math.floor(math.sqrt(n)))):
        if n % i == 0:
            return i

    return 1;

def CoinJam(number, call):
    if call == 14:
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


#f = open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\B-large.in", "r")
#a = []
#for line in f:
#    a.append(line)

#print a
#print a[0]


#with open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\SolCoinJam.txt", "w") as text_file:
#    for i in range(int(a[0])):
#        text_file.write("Case #%s: %s \n" %(i+1, RevengeOfThePancakes(a[1+i])))


