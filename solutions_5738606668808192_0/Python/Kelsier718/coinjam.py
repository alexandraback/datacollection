def findFac(integer):
    root = int(integer**0.5+1)
    for n in range(2, root+1):
        if integer%n == 0:
            return n
    return -1

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    print("Case #{}:".format(i))
    n, j = [int(s) for s in input().split(" ")]
    coinStr = '1'+''.join(str(0) for l in range(n-2))+'1'
    coins = []
    #print(coinStr)
    while j != 0:
        factors = [findFac(int(coinStr, k)) for k in range(2,11)]
        if not -1 in factors:
            print(coinStr+' '+' '.join(str(p) for p in factors))
            j = j - 1
        coinStr = "{0:b}".format(int(coinStr, 2)+2)
