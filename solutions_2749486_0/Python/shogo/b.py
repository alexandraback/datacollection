T = input()

ans = {}

try:
    f = open('cache.txt')
    for line in f:
        a = line.strip().split()
        if len(a) == 3:
            ans[(int(a[0]), int(a[1]))] = a[2]
        else:
            ans[(int(a[0]), int(a[1]))] = ""
except:
    c = {}
    que = [(0,0,"")]
    count = 0

    while count < 201 * 201:
        x, y, s = que.pop(0)
        if (x, y) not in ans:
            ans[(x, y)] = s
            c[(x, y)] = 0
            if -100 <= x <= 100 and -100 <= y <= 100:
                count += 1
        if c[(x, y)] < 3 and -200 <= x <= 200 and -200 <= y <= 200:
            que.append((x, y + len(s) + 1, s + 'N'))
            que.append((x, y - len(s) - 1, s + 'S'))
            que.append((x + len(s) + 1, y, s + 'E'))
            que.append((x - len(s) - 1, y, s + 'W'))
            c[(x,y)] += 1

    f = open('cache.txt', 'w')
    for x in range(-100, 101):
        for y in range(-100, 101):
            f.write("{0} {1} {2}\n".format(x, y, ans[(x, y)]))

for no in range(T):
    x, y = [int(s) for s in raw_input().split()]
    print "Case #{0}: {1}".format(no+1, ans[(x, y)] )

