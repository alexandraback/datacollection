import sympy

n = 32
j = 500

outfile = open("/tmp/coinbase_large", "w")

for i in xrange(2**(n-1)+1, 2**n, 2):
    s = bin(i)[2:]
    print s
    prime = False
    factors = []
    for base in xrange(2, 11):
        x = int(s, base)
        if sympy.ntheory.primetest.mr(x, [10]):
            prime=True
            break
        factor = sympy.ntheory.factor_.pollard_pm1(x)
        if not factor:
            prime=True
            break
        else:
            factors.append(factor)
    if not prime:    
        outfile.write(s + " " +  " ".join([str(i) for i in factors]) + "\n")
        j -= 1
    if j == 0:
        break
