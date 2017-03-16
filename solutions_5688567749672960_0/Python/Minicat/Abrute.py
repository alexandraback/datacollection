fi = open("A-small-attempt2.in", "r")
fo = open("A-small-attempt2-brute.out", "w")

T = int(fi.readline())

def flip(i):
    return int(str(i)[::-1])

# brute force :(
flips = [0, 1]
for i in range(2, 10 ** 6 + 1):
    best = flips[i-1]
    # see if can flip it instead
    flipped = flip(i)
    if len(str(flipped)) == len(str(i)) and flipped < len(flips) and flips[flipped] < best:
        best = flips[flipped]
    flips.append(best+1)

for case in xrange(1, T+1):
    N = int(fi.readline())
    out = "Case #{}: {}".format(case, flips[N])
    print out
    fo.write(out + "\n")

fi.close()
fo.close()
