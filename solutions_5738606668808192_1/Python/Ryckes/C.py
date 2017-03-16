
import math

# We don't need to check for dividers above a decently high number,
# since there are 2^N possible numbers, which for N = 16 is more than
# enough, and for 32, it's enormous.
dividersBelow = 100

def prime(n):
    maxn = int(math.sqrt(n))
    maxn = min(maxn, dividersBelow)
    for x in xrange(2, maxn + 1):
        if n % x == 0:
            return x
    return None

raw_input()
line = raw_input().split()
N = int(line[0]) # Size of jamcoin
J = int(line[1]) # Num of jamcoins

nums = []
firstNum = 2 ** (N - 1) + 1
while True:
    string = bin(firstNum)[2:]
    if string[-1] != "1":
        firstNum += 1
        continue

    dividers = []
    for base in xrange(2, 11):
        basedNum = int(string, base)
        divider = prime(basedNum)
        if divider is None:
            break
        else:
            dividers.append(divider)

    if len(dividers) == 9:
        nums.append((string, dividers))

    firstNum += 1
    if len(nums) == J:
        break

print "Case #1:"
for num in nums:
    print num[0],
    for divider in num[1]:
        print divider,
    print
