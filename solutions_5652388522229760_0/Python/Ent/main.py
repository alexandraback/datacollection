ln = int(input())
w = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

for i in range(ln):
    num = int(input())
    c = set()
    if num == 0:
        print('Case #' + str(i+1) + ": INSOMNIA")
    else:
        it = 1
        while True:
            d = it * num
            c.update([int(x) for x in list(str(d))])
            if c == w:
                print('Case #' + str(i+1) + ": " + str(d))
                break
            else:
                it += 1
