# MAX = int(bin(2**16-1)[2:].zfill(16)) + 5

# sieve = [i for i in range(MAX)]

# for i in range(2, int(MAX**0.5+1)):
#     if sieve[i] != i: continue
#     for j in range(2*i, MAX, i):
#         sieve[j] = i

# def comp(num):
#     return sieve[num] != num

def prime(num):
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False, i
    return True, 0

def compall(numstr):
    fac = []
    for b in range(2, 11):
        isprime, factor = prime(int(numstr, b))
        if isprime:
            return False, None
        fac.append(factor)
    return True, fac

print "Case #1:"

found = 0
for i in range(2**30):
    num = "1" + bin(i)[2:].zfill(30) + "1"
    c, f = compall(num)
    if c:
        found += 1
        print num, " ".join(map(str, f))
    if found == 500:
        break
