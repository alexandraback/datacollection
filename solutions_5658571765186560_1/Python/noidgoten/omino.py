file = open("omino.in", "r")
file2 = open("omino.out", "w")

t = int(file.readline())

def run(x, r, c, t):
    res = (x < 7)
    for i in range(1, x + 1):
        for j in range(1, x + 1):
            res = res and (not ((x >= i + j - 1 and ((i > r and j > r) or (i > c and j > c)) or (i > c and i > r) or (j > c and j > r)) or r * c % x != 0))
    for i in range(min(r,c) + 1, 1 + max(r,c)):
        if i + min(r,c) - 1 <= x:
            if 0 < (min(r,c) - 1)*(i-1) < x and r * c == 2 * x:
                res = False
    if res:
        file2.write("Case #" + str(t) + ": GABRIEL" + "\n")
    else:
        file2.write("Case #" + str(t) + ": RICHARD" + "\n")


for i in range(t):
    x = file.readline().split()
    run(int(x[0]), int(x[1]), int(x[2]), i+1)