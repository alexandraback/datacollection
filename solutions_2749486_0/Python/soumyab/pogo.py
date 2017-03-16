if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        xy = input().split()
        x = int(xy[0])
        y = int(xy[1])
        jumps = ""
        while x < 0:
            jumps += "EW"
            x += 1
        while x > 0:
            jumps += "WE"
            x -= 1
        while y < 0:
            jumps += "NS"
            y += 1
        while y > 0:
            jumps  += "SN"
            y -= 1
        print("Case #" + str(i+1) + ": " + jumps)
