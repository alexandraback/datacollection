import math
import itertools

def main():    
    f = open('C-small-attempt3.in', 'r')
    numberOfProblems = int(f.readline())
    out = open('C-small-attempt3.out','w')
    for case in range(0,numberOfProblems):
        line = f.readline()
        line = line.replace("\n","")
        C,D,V = line.split(" ")
        C = int(C)
        D = int(D)
        target = int(V)

        line = f.readline()
        line = line.replace("\n","")
        coins = line.split(" ")
        for x in range(0,len(coins)):
            coins[x] = int(coins[x])

        coinSums = {}
        coinSums[0]=True
        #count to target using coins
        coinSums = coinSummer(coins)

        #check missing sums
        missing = []
        possibleAddCoins = []
        missing,possibleAddCoins = missingSummer(coinSums,target,coins)


        countcoins = 0
        if len(missing) == 1:
            coins.append(-1)
        else:
            #try adding smallest denominations first
            countcoins = 0
            while len(missing) > 0:
                coins.append(possibleAddCoins[0])
                coinSums = coinSummer(coins)
                missing,possibleAddCoins = missingSummer(coinSums,target,coins)
                countcoins += 1
        
        
        answer = len(coins) - D
        #write answer to out
        out.write("Case #" + str(case+1) + ": " + str(answer) + "\n")





    f.close()
    out.close()

def missingSummer(coinSums,target,coins):
    missing = []
    possibleAddCoins = []
    for x in range(1,target):
        if x not in coinSums:
            missing.append(x)
    for x in range(1,target):
        if x not in coinSums:
            possibleAddCoins.append(x)
    return [missing,possibleAddCoins]


def coinSummer(coins):
    coinSums= {}
    coinSums[0]=True
    for x in range(0,len(coins)):
        #all combinations x + 1 size
        combs = itertools.combinations(coins,x+1)
        for i in combs:
            coinSums[sum(i)] = True
    return coinSums

def rev(n):
    return int(str(n)[::-1])

if __name__ == "__main__":
    main()
