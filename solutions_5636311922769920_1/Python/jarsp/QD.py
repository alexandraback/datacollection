f = open("D-large.in", "r")
g = open("D-large.out", "w")

def get_tiles(k, c, s):
    if k > s * c:
        return ["IMPOSSIBLE"]

    bot = max(-1, c - k - 1)
    temp = [k ** i for i in xrange(c - 1, bot, -1)]
    l = c - bot - 1

    tiles = []
    pos = 1
    for i in xrange(k):
        pos += i * temp[i % l]
        if i % l == l - 1 or i == k - 1:
            tiles.append(str(pos))
            pos = 1

    return tiles

f.readline()

counter = 1
for l in f:
    a = l.strip().split()
    k = int(a[0])
    c = int(a[1])
    s = int(a[2])

    g.write("Case #{}: ".format(counter) + " ".join(get_tiles(k, c, s)) + "\n")
    counter += 1
