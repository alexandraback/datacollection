import sys

file = sys.stdin
def getInt():
    return int(file.readline())


for i in range(getInt()):
    n = getInt()
    if n != 0:
        counter = 1
        vals = [0] * 10
        while 0 in vals:
            current = str(counter * n)
            for ch in current:
                vals[int(ch)] += 1
            #print(vals)
            counter += 1
        print("Case #" + str(i + 1) + ": " + str(current))
    else:
        print("Case #" + str(i + 1) + ": INSOMNIA")