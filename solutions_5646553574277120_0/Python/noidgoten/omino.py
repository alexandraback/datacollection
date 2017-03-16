file = open("money.in", "r")
file2 = open("money.out", "w")

t = int(file.readline())

def canCalc(sum, x, xc, c):
    if sum == x:
        return True
    res = False
    sum -= x
    for coin in coins:
        if coin < x:
            res = res or canCalc(sum, coin, c-1, c)
        if coin == x and xc > 0:
            res = res or canCalc(sum, coin, xc-1, c)
    return res

def run(c, d, coins, v, t):
    fr = 0
    done = False
    while not done:
        done = True
        for sum in range(1,v+1):
            res = False
            for coin in coins:
                if coin <= sum:
                    res = res or canCalc(sum, coin, c - 1, c)
            if not res:
                coins.append(sum)
                fr += 1
            done = done and res
    file2.write("Case #" + str(t) + ": " + str(fr) + "\n")

for i in range(t):
    x = file.readline().split()
    coins = [int(y) for y in file.readline().split()]
    run(int(x[0]), int(x[1]), coins, int(x[2]), i+1)

