
def prime(x):
    if not x & 1: 
        return 2
    for d in range(3, 100, 2):
        if x % d == 0:
            return d
    return -1

def isprime(x):
    return prime(x) == -1

def iscoin(x):
    if x[0] != '1' or x[-1] != '1':
        return False
    for b in range(2, 11):
        if isprime(int(x, b)):
            return False
    return True

def getcoindiv(x):
    ld = []
    for b in range(2, 11):
        ld.append(str(prime(int(x, b))))
    return ld

def nextcoins(sc):
   return [x + y for x in sc for y in sc if iscoin(x + y)]

                 
s8 = [x for x in ["{0:b}".format(i) for i in range(128, 256)] if iscoin(x)]
s16 = nextcoins(s8)

input()
inp = map(int, raw_input().split())

if inp[0] == 16:
    coins = [s16[i] for i in range(0, inp[1])]
else:
    s32 = nextcoins(s16)
    coins = [s32[i] for i in range(0, inp[1])]

print "Case #1:"
for x in coins:
    print "%s %s" % (x, " ".join(getcoindiv(x)))
