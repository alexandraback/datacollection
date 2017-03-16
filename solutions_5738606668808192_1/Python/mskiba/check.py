raw_input()
c = []

for _ in range(50):
    x = raw_input().strip()
    x = map(int, x.split(' '))
    n = str(x[0])
    d = x[1:]

    if n in c:
        print "ERROR"
    c.append(n)
    
    for i in range(2, 11):
        num = int(n, i)
        if num % d[i - 2] != 0 or d[i - 2] == 1 or d[i - 2] == num :
            print n
            print num
            print d[i - 2]
            print i
            print '-----'