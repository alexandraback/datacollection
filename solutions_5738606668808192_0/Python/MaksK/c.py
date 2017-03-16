from itertools import product


def iscomp(n):
    for i in range(2, 10000):
        if not n % i:
            return i
    return False


input()
result = []
n, j = map(int, input().split())
for ii, coin in enumerate(product("01", repeat=n-2)):
    coin = "1" + "".join(coin) + "1"
    # if ii % 1 == 0:
    #     print("\t", ii, coin)
    divs = []
    for i in range(2, 11):
        m = int(coin, i)
        divs.append(iscomp(m))
        if not divs[-1]:
            break
    else:
        # print(coin)
        result.append((coin, divs))
        if len(result) == j:
            break
print("Case #1:")
for c, divs in result:
    print(c, " ".join(map(str, divs)))
