import copy

primes = [2]

for i in range(3, 65536):
    flag = True
    for prime in primes:
        if i % prime == 0:
            flag = False
            break
    if flag:
        primes.append(i)

input()
[N, J] = [eval(x) for x in input().split()]
count = 0
cur = ['0' for _ in range(N)]
cur[-1] = '1'
cur[0] = '1'
rs = []
rsd = []

def check():
    divisor = []
    for base in range(2, 11):
        flag = True
        num = 0
        for digit in cur:
            num *= base
            if digit == '1':
                num += 1
        for prime in primes:
            if prime >= num:
                break
            if num % prime == 0:
                divisor.append(prime)
                flag = False
                break
        if flag:
            return False
    rs.append(copy.copy(cur))
    rsd.append(copy.copy(divisor))
    return True

def nextcur():
    if cur[-2] == '0':
        cur[-2] = '1'
    else:
        cur[-2] = '0'
        for i in range(3, len(cur)):
            if cur[-i] == '1':
                cur[-i] = '0'
            else:
                cur[-i] = '1'
                break

while count < J:
    if check():
        count += 1
    nextcur()

print('Case #1:')
for i in range(J):
    print('{} {}'.format(''.join(rs[i]), ' '.join(str(x) for x in rsd[i])))
