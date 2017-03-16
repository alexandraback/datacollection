import sys

def getdiv(n):
    if n%2==0:
        return 2
    for i in xrange(3, int(n**0.5), 2):
        if n%i==0:
            return i
    return None

def check(n, divs):
    for base in xrange(2, 11):
        if int(bin(i)[2:], base) % divs[base-2] > 0:
            return False
    return True

input_filename = sys.argv[1]

count = 0

with open(input_filename, "r") as infile:
    t = infile.readline()
    n, j = map(int, infile.readline().split())
    with open("out.txt", "w") as outfile:
        coins = dict()
        if n<17:
            i = 2**(n-1) + 1
            while (i<2**(n)-1):
                divs = []
                for base in xrange(2, 11):
                    div = getdiv(int(bin(i)[2:], base))
                    if not div:
                        break
                    divs.append(div)
                if div:
                    coins[i] = divs
                    count += 1
                    print i, coins[i], check(i, coins[i])
                    if count>=j:
                        break
                i += 2
        else:
            for div in xrange(11, 1000, 2):
                if (div%3 == 0 or div%5== 0):
                    continue
                lc = 0
                i = 2**(n-1) + 1
                if (i%div>0):
                    i = i - i%div + div
                while (i<2**(n)-1):
                    for base in xrange(2, 11):
                        if int(bin(i)[2:], base) % div > 0: break
                    else:
                        if i not in coins:
                            coins[i] = [div]*9
                            count += 1
                            print i, coins[i], check(i, coins[i])
                    i += 2*div
                    if count>=j:
                        break
        outfile.write("Case #1:\n")
        for coin, divs in coins.items():
            outfile.write(bin(coin)[2:]+" "+" ".join(map(str, divs))+"\n")