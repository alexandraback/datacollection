import random

sieve = [ i >= 2 for i in range(10**3) ]
for p in range(2,len(sieve)):
    if sieve[p]:
        q = p*p
        while q < len(sieve):
            sieve[q] = False
            q += p
primes = [ x for x in range(len(sieve)) if sieve[x] ]

def remainder(S,base,p):
    answer = 0
    for x in S: answer = (answer*base+int(x)) % p
    return answer

def generate(N):
    while True:
        S = '1' + ''.join( random.choice('01') for n in range(N-2) ) + '1'
        witnesses = [ None for base in range(11) ]
        for base in range(2,11):
            for p in primes:
                if remainder(S,base,p) == 0:
                    witnesses[base] = p
                    break
        if (not None in witnesses[2:]):
            return S, witnesses

N = 16
J = 50

results = {}

while len(results) < J:
    number, witnesses = generate(N)
    results[number] = witnesses

print('Case #1:')
for number in results:
    print(number, end='')
    for w in results[number][2:]: print(' {}'.format(w), end='')
    print()
