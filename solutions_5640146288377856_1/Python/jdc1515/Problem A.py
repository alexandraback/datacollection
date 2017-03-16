with open("A-large.in") as f:
    lines = f.readlines()

outputname = 'outputAlarge.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def ceildiv(a, b):
    return -(-a // b)

for i in range(cases):
    nums = lines[linenum].split(" ")
    nums = [int(j) for j in nums]
    linenum += 1

    R, C, W = nums

    width = C // W
    numtofirst = width * R
    left = W - 1
    right = C - width * W
    rem = W - 1
    total = numtofirst
    if left + right == rem:
        total += rem
    else:
        total += rem + 1

    f.write("Case #" + str(i+1) + ": " + str(total)+"\n")


f.close()

with open(outputname, 'r') as f:
    print(f.read())
