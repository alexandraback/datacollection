from sympy.ntheory import nextprime
from sympy.ntheory.factor_ import primefactors
from sympy.ntheory.primetest import isprime

def main_code(x):
    N, J = tuple(map(int, input().split()))
    current = 1 + (2 ** (N - 1))
    print("Case #" + str(x + 1) + ":")
    for _ in range(J):
        prime = True
        while prime:
            jamcoin = format(current, 'b')
            current += 2
            prime = False
            proof = []
            for base in range(2,11):
                interpretation = int(jamcoin,base)
                if isprime(interpretation):
                    prime = True
                    break
                else:
                    proof.append(str(primefactors(interpretation)[0]))
                    
        print(jamcoin, " ".join(proof))

T = int(input())
for x in range(T):
    main_code(x)
