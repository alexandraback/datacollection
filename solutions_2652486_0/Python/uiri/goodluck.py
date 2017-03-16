import sys

stdin = sys.stdin.readlines()
stdin.pop(0)
print "Case #1:"
rnmk = stdin.pop(0).split(' ')
k = int(rnmk.pop())
m = int(rnmk.pop())
n = int(rnmk.pop())
r = int(rnmk.pop())
for i in xrange(r):
    b = []
    p = stdin.pop(0).split(' ')
    for j in p:
        j = int(j)
        a = m
        for c in b:
            if j%c == 0:
                j /= c
        while a > 1:
            while j%a == 0:
                j /= a
                b.append(a)
                if len(b) == n:
                    break
            a -= 1
            if len(b) == n:
                break
        if len(b) == n:
            break
    while len(b) < n:
        b.append(2)
    printstr = ""
    for j in b:
        printstr += str(j)
    print printstr
