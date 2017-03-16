t = int(input())

def addD(used, a):
    if a == 0:
        used.add(0)
    while a > 0:
        used.add(a % 10)
        a //= 10
        

for curt in range(1, t + 1):
    n = int(input())
    if n == 0:
        print("Case #%d: INSOMNIA" % curt)
    else:
        used = set()
        nn = n
        addD(used, nn)
        while len(used) < 10:
            nn += n
            addD(used, nn)
        print("Case #%d: %d" % (curt, nn))