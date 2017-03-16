from math import sqrt, floor

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        xy = input().split()
        x = int(xy[0])
        y = int(xy[1])
        jumps = list()
        abs_x = abs(x)
        abs_y = abs(y)
        total = abs_x + abs_y
        a = floor(sqrt(2*total))
        while a*(a+1) < 2*total:
            a += 1
        tot = a*(a+1)//2
        if (tot - total) % 2 != 0:
            a += 1
            tot = a*(a+1)//2
        neg = (tot - total)//2
        for _ in range(a):
            jumps += ["_"]
        jumps[neg-1] = "-"
        while abs_y > 0:
            for blah in range(len(jumps)-1,-1, -1):
                if blah+1 > abs_y:
                    break
                else:
                    if jumps[blah] == "_":
                        abs_y -= (blah+1)
                        jumps[blah] = "N"
            if abs_y > 0:
                if jumps[abs_y-1] == "_":
                    jumps[abs_y-1] = "N"
                else:
                    jumps[0] = "N"
                    jumps[abs_y-2] = "N"
            abs_y = 0
        jumps = ''.join(jumps)
        if y < 0:
            jumps = jumps.replace("N", "S")
        if x >= 0:
            jumps = jumps.replace("_", "E")
            jumps = jumps.replace("-", "W")
        elif x < 0:
            jumps = jumps.replace("_", "W")
            jumps = jumps.replace("-", "E") 
        print("Case #" + str(i+1) + ": " + jumps)
