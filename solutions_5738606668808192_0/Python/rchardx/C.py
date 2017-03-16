def trans(a, b):
    num = 0
    exp = 1
    while a > 0:
        num += exp*(a % 2)
        exp *= b
        a /= 2
    return num


def checkprime(x):
    div = 3
    while div*div <= x:
        if x % div == 0:
            return div
        div += 2
    return -1

print 'Case #1:'
T = int(raw_input())
N = int(raw_input())
J = int(raw_input())
print T,N,J
i = (1 << (N-1))+1
ans = 0
while ans < J:
    #print trans(i, 10)
    t = []
    flag = True
    for k in xrange(2, 11):
        tmp = checkprime(trans(i, k))
        if tmp == -1:
            flag = False
            break
        else:
            t.append(tmp)
    if flag:
        print trans(i, 10),
        for k in t:
            print k,
        print
        ans += 1
    i += 2
