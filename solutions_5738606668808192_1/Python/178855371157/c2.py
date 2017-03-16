print "Case #1:"

N = 32
J = 500

def factor(n):
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    if n % 5 == 0:
        return 5
    i = 6
    while i * i < n:
        if n % (i+1) == 0:
            return i+1
        if n % (i+5) == 0:
            return i+5        
        i += 6
        if i > 100000:
            break
    return 1

def jamcoin_factors(c):
    ret = []
    for base in range(2,11):
        f = factor(int(c, base))
        if f == 1:
            return []
        ret.append(f)
    return ret

# c = 0b10000000000000000000000000000001
c = 0b10101110101010101010101110101001
count = 0
while count < J:
    jf = jamcoin_factors(bin(c)[2:])
    if jf:
        count += 1
        print bin(c)[2:] + ' ' + ' '.join(str(f) for f in jf)
    c += 32
