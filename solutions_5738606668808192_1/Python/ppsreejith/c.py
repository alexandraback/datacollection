from collections import defaultdict
primes = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541]

T = int(input())
N, J = map(int, raw_input().split())
x = int("1"+"0"*(N-2)+"1", 2)
ans = defaultdict(list)

def add_factor(coin, fact):
    ans[coin].append(str(fact))

def remove_coin(coin):
    if coin in ans:
        ans.pop(coin)

def find_factor(num):
    for prime in primes:
        if num % prime == 0:
            return prime
    return False

while len(ans) < J:
    x += 2
    coin = bin(x)[2:]
    for base in xrange(2, 11):
        no = int(coin, base)
        fac = find_factor(no)
        if fac:
            add_factor(coin, fac)
        else:
            remove_coin(coin)
            break

print "Case #1:"
for coin in ans:
    print "%s %s" % (coin, " ".join(ans[coin]))
