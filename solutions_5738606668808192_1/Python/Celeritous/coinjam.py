def problem(inPath, outDir = ""):
    def solve(inPath, processor, outDir = ""):
        from multiprocessing import Pool
        from os import path

        inf = open(inPath, 'rU')
        stem = path.basename(inPath)
        name, extension = path.splitext(stem)
        outName = name + ".out"
        outPath = path.join(outDir, outName)
        outf = open(outPath, 'w')

        inf.readline() #discard the line which tells us how many lines of input there are
        pool = Pool()
        outputs = pool.map(processor, (line.strip() for line in inf))
        for i, result in enumerate(outputs, 1):
            string = "Case #%s:\n%s" % (i, result)
            if i > 1:
                outf.write("\n")
            outf.write(string)

    solve(inPath, processor, outDir)

def processor(string):
    return printer(*string.split(' '))

def printer(N, J):
    results = inner(int(N), int(J))
    return "\n".join("{} {}".format(j, " ".join(map(str, d))) for j, d in results)

def inner(N, J):
    BASES = list(range(2, 10 + 1))
    candidates = [b + 1 for b in BASES]
    total = 0
    for jamcoin in allJamcoins(N):
        if all(int(jamcoin, b) % c == 0 for b, c in zip(BASES, candidates)):
            yield jamcoin, candidates
            total += 1
            if total >= J:
                return

def allJamcoins(N):
    variable = N - 2
    for i in range(2**variable):
        b = bin(i)[2:]
        s = b.rjust(variable, "0")
        yield "1{}1".format(s)

def anyDivisor(x):
    from math import sqrt
    for prime in PRIMES:
        if x % prime == 0:
            return prime
        if prime >= sqrt(x): 
            return float('inf')
    return float('inf') # just assume it's prime if we get this far

## don't need this any more
##def sieve(N):
##    primalities = [True]*N
##    primalities[0] = primalities[1] = False
##
##    for prime, primality in enumerate(primalities):
##        if primality:
##            yield prime
##            for index in range(prime*prime, N, prime):
##                primalities[index] = False
##
##PRIMES = list(sieve(int(1e7)))
