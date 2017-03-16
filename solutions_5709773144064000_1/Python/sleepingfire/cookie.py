import sys

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

for i in range(T):
    C, F, X = [float(z) for z in file.readline().split()]
    cookie = 0
    sec = 0
    rate = 2
    while cookie + C < X:
        cookie += C
        sec += C / rate
        if (X - cookie) / rate > (X -(cookie - C)) / (rate + F):
            cookie -= C
            rate += F
    sec += (X - cookie) / rate

    print("Case #%d: %f"%(i+1, sec))
