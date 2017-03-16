import sys
import itertools

def denom(coin, i):
    coin = int(coin,i)
    root = int(coin**0.5)
    for i in range(2,root+1):
        if coin%i == 0:
            return i
    return 1

def getValid(coin):
    ret = []
    for i in range(2,11):
        ret.append(denom(coin,i))
        if ret[i-2] == 1:
            return []
    return ret


t = sys.stdin.readline()
vals = sys.stdin.readline().split(' ')
n = int(vals[0])
j = int(vals[1])
print("Case #1:")

for center in itertools.product(['0','1'],repeat=n-2):
    coin = '1' + ''.join(center) + '1'
    # print(coin)
    validation = getValid(coin)
    if len(validation) != 0 :
        j -= 1        
        print(coin, end=" ")
        i = 2
        for v in validation:
            print(v, end=" ")
            # print(int(''.join(coin), i)/v, end=" ")
            i += 1
        print()
    if j <= 0:
        break