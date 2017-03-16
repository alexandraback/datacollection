T = int(input())

# My pre-calculation was to decide how many primes were worth testing
# If J is close to the maximum possible for a certain N, you will need a longer list
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

def test_prime(x):
    for p in primes:
        if x % p == 0:
            return p
    return -1

for test in range(T):
    print('Case #' + str(test+1) + ':')
    N, J  = list(map(int,input().split()))
    attempt = [1] * N
    att_base2 = 2**N - 1
    jams_found = 0
    while jams_found < J:
        factors = []
        for base in range(2,11):
            att_base = 0
            for position in range(N):
                att_base += attempt[position] * (base ** (N - position - 1))
            lastfactor = test_prime(att_base)
            if lastfactor == -1:
                break
            else:
                factors.append(lastfactor)
        if len(factors) == 9:
            print(''.join(str(x) for x in attempt) + ' ' + ' '.join(str(x) for x in factors))
            jams_found += 1
        att_base2 -= 2
        att_string = bin(att_base2)[2:]
        attempt = [int(x) for x in att_string]