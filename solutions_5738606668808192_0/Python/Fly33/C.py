from sys import stdin, stdout
import random

# is_prime = []
# prime = []
# value = []
# 
# def init():
#     global value
#     
#     value.append([])
#     value.append([])
# 
#     for i in range(2, 11):
#         value.append([])
#         value[i].append(0)
#         for j in range(1, 0x10000):
#             value[i].append(value[i][j>>1] * i + (j&1))
#             
#     global is_prime, prime
#     
#     is_prime.append(False)
#     is_prime.append(False)
#     for i in range(2, 0x10000):
#         j = 0
#         while j < len(prime) and prime[j] * prime[j] <= i:
#             if i % prime[j] == 0:
#                 is_prime.append(False)
#                 break
#             j += 1
#         else:
#             is_prime.append(True)
#             prime.append(i)

def solve(test_id):
    global value, is_prime, prime
    print("Case #{}:".format(test_id))

    n = 16
    j = 50

#     for _ in range(j):
#         x = random.getrandbits(16) | 0x8001
#         z = []
#         for i in range(2,11):
#             v = value[i][x]
#             for k in range(len(prime)):
#                 if v % prime[k] == 0:
#                     z.append(prime[k])
#                     break
#             else:
#                 break
#         else:
#             print(value[10][x], *z)

    for i in range(50):
        x = (i<<1) | 0x81
        for j in range(8):
            if x & (1<<(7-j)):
                print('11', end='')
            else:
                print('00', end='')
        print(' ', end='')
        y = []
        for j in range(2,11):
            y.append(j+1)
        print(*y)

def main():
#     init()
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
