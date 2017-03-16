def not_prime(x, prime_number):
    for idx in prime_number:
        if idx * idx <= x and x % idx == 0:
            return idx
        if idx * idx > x:
            break
    return -1


maxn = 10000
prime = []
for i in range(2, maxn + 1):
    ok = True;
    for j in prime:
        if i % j == 0:
            ok = False
            break
        if j * j > i:
            break
    if ok:
        prime.append(i)
N = 32
J = 500
n = N - 2
ans1 = [0 for i in range(J)]
ans2 = [[0 for j in range(2, 11)] for i in range(J)]
print ans2
currj = 0
for i in range(0, 10000):
    curr = (i << 1) + (1L << (n + 1)) + 1L
    flag = True
    for base in range(2, 11):
        tmp = 0
        for j in range(n + 1, -1, -1):
            tmp = tmp * base + (curr >> j) % 2
        tmpx = not_prime(tmp, prime)
        if tmpx == -1:
            flag = False
            break
        else:
            ans2[currj][base - 2] = tmpx
            if base == 10:
                ans1[currj] = tmp
    if flag:
        currj += 1
        print currj
    if currj == J:
        break

for i in range(J):
    print("%d" % ans1[i])
    for j in range(2, 11):
        print(" %d" % ans2[i][j - 2])
    print("\n")

newfile = open("c.out", 'w')
newfile.write("Case #1: \n")
for i in range(J):
    newfile.write("%d" % ans1[i])
    for j in range(2, 11):
        newfile.write(" %d" % ans2[i][j - 2])
    newfile.write("\n")