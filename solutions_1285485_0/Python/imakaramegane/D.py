import sys
import math

def testcases():
    with open(sys.argv[1], "r") as f:
        T = int(f.readline())
        for x in range(T):
            H, W, D = [ int(v) for v in f.readline().split() ]
            room = []
            for h in range(H):
                room.append(f.readline()[:-1])
            yield x + 1, H, W, D, room

def main():

    for X, H, W, D, room in testcases():
        
        for py, row in enumerate(room[1:-1]):
            px = row[1:].find("X")
            if px >= 0:
                break
        px += (W - 2) * D
        py += (H - 2) * D

        mroom = []
        odd = D % 2
        for row in room[1:-1]:
            row = row[1:-1]
            m = "".join(reversed(row))
            if odd:
                mroom.append((m + row) * D + m)
            else:
                mroom.append((row + m) * D + row)
        m = list(reversed(mroom))
        if odd:
            mroom = (m + mroom) * D + m
        else:
            mroom = (mroom + m) * D + mroom

        degrees = set()
        for iy, row in enumerate(mroom):
            for ix, cell in enumerate(row):
                if ix == px and iy == py:
                    continue
                if cell == "X":
                    mx = ix - px
                    my = iy - py
                    dstnc = math.hypot(mx, my)
                    if dstnc <= D:
                        degrees.add(math.atan2(my, mx))
        y = len(degrees)

        print("Case #{:d}: {:d}".format(X, y))

if __name__=="__main__":
    main()
