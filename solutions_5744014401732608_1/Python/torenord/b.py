from sys import stdin

T = int(next(stdin))

for x in range(1, T+1):
    B, M = map(int, next(stdin).strip().split(" "))
    if M > 2**(B-2):
        y = "IMPOSSIBLE"
    else:
        y = "POSSIBLE\n"
        if M == 2**(B-2):
            z = "1"
        else:
            z = "0"
            M += 1
        y += ("{0:0" + str(B-1) + "b}").format(M-1) + z + "\n"
        for i in range(2, B+1):
            y += "0"*(i) + "1"*(B-i) + "\n"
        y = y[:-1]
    print("Case #{0}: {1}".format(x, y))
