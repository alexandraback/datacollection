N=16
J=50
primes = [2]

for i in range(3, 10000):
    for p in primes:
        if i % p == 0:
            break
    else:
        primes.append(i)
res = []
num = 2**(N-1) + 1
while len(res) < J:
    div = []
    jc = bin(num)[2:]
    
    for base in range(2, 11):
        nb = int(jc, base)
        
        nonprime = False
        for p in primes:
            if nb % p == 0:
                div.append(p)
                nonprime = True
                break
        
        if not nonprime:
            break

    if nonprime:
        print(jc)
        res.append([jc, div])
    num += 2
