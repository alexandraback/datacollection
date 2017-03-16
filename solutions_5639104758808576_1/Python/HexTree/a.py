g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        smax, string = [x for x in f.readline().split()]
        smax = int(smax)
        standing = 0
        friends = 0
        for index in range(smax + 1):
            if string[index] != '0' and standing < index:
                friends += (index - standing)
                standing = index
            standing += int(string[index])
        g.write("Case #%d: %d\n" % (r+1, friends))
f.close()
g.close()