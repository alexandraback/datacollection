#!/usr/bin/python3
import itertools

def binaryPalindromesGen(length): 
    evenLength = length%2==0
    binaries = ["".join(seq) for seq in itertools.product("01", repeat=int(length/2))]
    if evenLength:
        for i in binaries:
            yield i+''.join(reversed(i))
    else:
        for i in binaries:
            yield i+'1'+''.join(reversed(i))
            yield i+'0'+''.join(reversed(i))


testsNb = int(input()) # Should be 1
for test in range(1, testsNb+1):
    print("Case #" + str(test) + ":")
    infos = [int(n) for n in input().split()]
    N = infos[0]
    J = infos[1]

    gen = binaryPalindromesGen(N-2); 
    # If the sum of all odd bits = the sum of all event bits then it is divisible by the base + 1
    # This is true for all binary palindromes so generate a couple of them.
    for i in range(J):
        print("1" + next(gen) + "1 3 4 5 6 7 8 9 10 11");
