import sys

temp = sys.stdout
sys.stdout = open(r'C:\Users\Spin\Desktop\o.txt', 'a')

Q = open(r'C:\Users\Spin\Desktop\A-small-attempt0.in')
T = int(Q.readline())


def q1(n):
    if n is 0:
        return 'INSOMNIA'

    pool = set('1234567890')
    c = 1
    while pool:
        for digit in str(c*n):
            if digit in pool:
                pool.remove(digit)

        c += 1
    return (c-1)*n


for i in range(T):
    print('Case #%r:' % (i + 1), end=' ')
    n = int(Q.readline())
    print(q1(n))


sys.stdout = temp
