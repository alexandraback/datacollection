import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

# 0 1   4 -1
# 1 i   5 -i
# 2 j   6 -j
# 3 k   7 -k
def multi(a, b):
    table = [
        [0, 1, 2, 3],
        [1, 4, 3, 6],
        [2, 7, 4, 1],
        [3, 2, 5, 4]
    ]
    #print(a, b)
    c = 0
    if a >3:
        c = 1
        a -= 4
    if b >3:
        c+= 1
        b -= 4

    ans = table[a][b]
    if c == 1:
        if ans >3:
            ans -= 4
        else:
            ans += 4
    return ans

def power(a, n):
    t = [0]
    c = 0
    while True:
        c = multi(c, a)
        if c == t[0]: break
        t.append(c)
    return t[n%len(t)]

def solve():
    [n, X] = [int(c) for c in input().split()]
    a = list(input())
    for i in range(n):
        if a[i] == 'i':
            a[i] = 1
        if a[i] == 'j':
            a[i] = 2
        if a[i] == 'k':
            a[i] = 3
    count = 0
    #print(a)
    for i in range(n):
        count = multi(count, a[i])


    #power(count, X)
    #print('Goo')


    if power(count, X) != multi(multi(1, 2), 3):
        return 'NO'



    i1 = 0
    c = 0
    while i1 <= n*8:
        if c == 1:
            break
        c = multi(c, a[i1%n])
        i1 += 1
    if i1 > n*8:
        return 'NO'

    i2 = 0
    c = 0
    while i2 <= n*8:
        if c ==3:
            break
        c = multi(a[(n-i2-1)%n], c)
        i2 += 1
    if i2 > n*8:
        return 'NO'

    if (i1+i2<=n*X):
        return 'YES'
    else:
        return 'NO'


for T in range(int(input())):
    print('Case #%d: %s' % (T+1, solve()))