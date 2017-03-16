import sympy

n = 16
j = 50


for i in range(2**(n-1)+1, 2**n, 2):
    s = bin(i)[2:]
    prime = False
    factors = []
    for base in range(2, 11):
        x = int(s, base)
        if sympy.ntheory.primetest.mr(x, [10]):
            prime=True
            break
        factors.append(sympy.ntheory.factorint(x).keys()[0])
    if not prime:    
        print s, " ".join([str(i) for i in factors])
        j -= 1
    if j == 0:
        break
