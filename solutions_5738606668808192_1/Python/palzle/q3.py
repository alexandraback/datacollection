import sys
from time import time
from itertools import product

temp = sys.stdout
sys.stdout = open(r'C:\Users\Spin\Desktop\o.txt', 'a')

Q = open(r'C:\Users\Spin\Desktop\t.txt')
# Q = open(r'C:\Users\Spin\Desktop\D-large.in')
T = int(Q.readline())


# def q1(n):
#     if n is 0:
#         return 'INSOMNIA'
#
#     pool = set('1234567890')
#     c = 1
#     while pool:
#         for digit in str(c*n):
#             if digit in pool:
#                 pool.remove(digit)
#
#         c += 1
#     return (c-1)*n

# def q2(s):
#     m = len(s)
#     l = []
#     for i in range(m):
#         if i is 0 or s[i] != l[-1]:
#             l.append(s[i])
#     if l[-1] == '+':
#         l.pop()
#     return len(l)

# def q4small(k, c, s):
#     # print(k, c, s)
#     return ' '.join(map(str, range(1, k+1)))

# def q4(k, c, s):
#     if k == 1:
#         return '1'
#
#     if c == 1:
#         if s == k:
#             return ' '.join(map(str, range(1, k + 1)))
#         else:
#             return 'IMPOSSIBLE'
#
#     if s < (k + 1) // 2:
#         return 'IMPOSSIBLE'
#
#     res = []
#     size = k ** (c - 1)
#     for i in range(1, k, 2):
#         res.append((i - 1) * size + i + 1)
#     if k % 2:
#         res.append(size * k)
#
#     return ' '.join(map(str, res))


def findPrime(n=100000000):
    m = (n-1)//2
    table = [True] * m
    res = [2]
    for i in range((int(n**0.5)-1)//2):
        if table[i] is True:
            for j in range(2*i*i+6*i+3, m, 2*i+3):
                table[j] = False
    for k in range(m):
        if table[k] is True:
            res.append(2*k+3)
    # res = [2*k+3 for k in range(m) if table[k]]
    return res

# s = time()
# print(findPrime(10000000))
# findPrime()
# f = time()
# print(f-s)




def geneNum(n = 14):
    for i in product('01', repeat=n):
        yield i


primes = findPrime()

def q3(n, j):
    res = {}
    for vector in geneNum(n-2):
        if len(res) == j:
            return res

        divisor = []
        for base in range(2, 11):
            num = 1
            for i in range(n-2):
                num += int(vector[i]) * base ** (i+1)
            num += base ** (n-1)

            for prime in primes:
                if num % prime is 0:
                    divisor.append(prime)
                    break

            else:
                break

            continue

        else:
            res[num] = divisor

        continue

# print(q3(6,3))

for i in range(T):
    # print('Case #%r:' % (i + 1), end=' ')
    print('Case #%r:' % (i + 1))
    q = map(int, Q.readline().split())
    # print(q1(n))
    res = q3(*q)
    for num in res:
        print(num, end=' ')
        print(' '.join(map(str, res[num])))



sys.stdout = temp
