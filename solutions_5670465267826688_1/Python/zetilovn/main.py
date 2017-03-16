import sys

input = open('///Users/Zetilov/Downloads/C-large.in.txt', 'r')
output = open('output.txt', 'w')


#input = sys.stdin
#output = sys.stdout

def mul(x, y):
    #print(x, y)
    global tab
    r = tab[abs(x)][abs(y)]
    if x * y > 0:
        return r
    return -r

def pow(x, n):
    if n == 0:
        return 1
    if n % 2 == 1:
        return mul(x, pow(x, n - 1))
    z = pow(x, n // 2)
    return (mul(z, z))

tab = [[0, 0, 0, 0, 0], [0, 1, 2, 3, 4], [0, 2, -1, 4, -3], [0, 3, -4, -1, 2], [0, 4, 3, -2, -1]]
sl = {'1': 1, 'i': 2, 'j': 3, 'k': 4}
t = int(input.readline())
for z in range(t):
    print(z)
    res = 'NO'
    n, k = map(int, input.readline().split())
    arr = []
    for i in input.readline():
        if i != '\n':
            arr.append(sl[i])
    r = 1
    for i in arr:
        r = mul(r, i)
    if pow(r, k) == -1:
        a = 1
        for i in range(n):
            #print(i)
            a = mul(a, arr[i])
            for x in range(4):
                ra = mul(pow(r, x), a)
                #print(a, ra, i,  x)
                if ra != 2 or res == "YES":
                    continue
                #print(i, x)
                b = 1
                for j in range(n):
                    b = mul(arr[n - 1 - j], b)
                    for y in range(4):
                        rb = mul(b, pow(r, y))
                        #print(i, x, j, y, b, rb)
                        if rb == 4:
                            if x + y < k - 1 or x + y == k - 1 and i + j < n - 2:
                                res = 'YES'


    print('Case #', z + 1, ': ', end = '', sep = '', file = output)
    print(res, file = output)