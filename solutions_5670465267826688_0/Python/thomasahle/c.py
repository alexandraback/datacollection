import sys
read = lambda f=int: list(map(f, sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

# 0  1  2  3   4   5   6   7
# 1, i, j, k, -1, -i, -j, -k
mul = [
    [0, 1, 2, 3, 4, 5, 6, 7],
    [1, 4, 3, 6, 5, 0, 7, 2],
    [2, 7, 4, 1, 6, 3, 0, 5],
    [3, 2, 5, 4, 7, 6, 1, 0],
    [4, 5, 6, 7, 0, 1, 2, 3],
    [5, 0, 7, 2, 1, 4, 3, 6],
    [6, 3, 0, 5, 2, 7, 4, 1],
    [7, 6, 1, 0, 3, 2, 5, 4]
]
conv = {'i':1, 'j':2, 'k':3}

def pow(x, n):
    if n == 0:
        return 0
    if n % 2 == 0:
        return pow(mul[x][x], n//2)
    return mul[pow(x, n-1)][x]

def find(xs, x):
    v = 0
    for i in range(len(xs)):
        if v == x:
            return i
        v = mul[v][xs[i]]
    return -1

def rfind(xs, x):
    v = 0
    for i in range(len(xs)):
        if v == x:
            return i
        v = mul[xs[i]][v]
    return -1

def solve(X, xs):
    # print('0', xs)
    val = 0
    for x in xs:
        val = mul[val][x]
    if pow(val, X) != mul[1][mul[2][3]]:
        # print('A', pow(val, X), mul[1][mul[2][3]])
        return "NO"

    a = find(xs*4, 1)
    b = rfind(xs[::-1]*4, 3)
    if a == -1 or b == -1:
        # print('B', a, b)
        return "NO"

    # print('C', a, X*len(xs)-b)
    if a < X*len(xs)-b:
        return "YES"

    return "NO"

def mulall(xs):
    val = 0
    for x in xs:
        val = mul[val][x]
    return val

# import random
# while True:
#     a,b,c = [random.choice(range(8)) for _ in range(3)]
#     if mul[a][mul[b][c]] != mul[mul[a][b]][c]:
#         print(a,b,c)
#         print( mul[a][mul[b][c]], mul[mul[a][b]][c])
#         break
#     xs = [random.choice(range(8)) for _ in range(4)]
#     if mulall(xs) != mul[mulall(xs[:2])][mulall(xs[2:])]:
#         print(xs)
#         break

# print(mulall(conv[c] for c in 'jk'))
# print(mulall(conv[c] for c in 'kkkjjkjiikkikjijiji'))
# print(mulall(conv[c] for c in 'jjikkjikj'))
# print(mulall(conv[c] for c in 'jkkkkjjkjiikkikjijijijjikkjikj'))
# print(mul[1][mul[2][3]])
# print(mulall(conv[c] for c in 'ijk'))

# jk kkkjjkjiikkikjijiji jjikkjikj

def solve2(X, xs):
    xs2 = xs*X
    # print(xs2)
    # print(mul[2][mul[1][2]])
    # print(mul[mul[2][1]][2])
    # print(mulall([2,1,2]))
    # print(mulall(xs2[:3]))
    for i in range(len(xs2)+1):
        for j in range(i, len(xs2)+1):
            if mulall(xs2[:i]) == 1 and mulall(xs2[i:j])==2 and mulall(xs2[j:])==3:
                print('?', i, j)
                return "YES"
    return "NO"

T, = read()
for t in range(T):
    _, X = read()
    s, = read(str)
    xs = [conv[c] for c in s]
    # if (X*len(xs))**3 < 10**9:
        # print(_, X, s)
        # print('Xxxx #{}: {}'.format(t+1, solve2(X, xs)))
        # assert solve2(X,xs)==solve(X,xs)
    print('Case #{}: {}'.format(t+1, solve(X, xs)))
