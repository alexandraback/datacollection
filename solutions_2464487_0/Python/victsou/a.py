n = int(raw_input())

for i in range(n):
    r, t = map(int,raw_input().split())

    tot = (r+1)*(r+1) - (r*r)
    count = 1
    r = r + 2
    while True:
        tot += (r+1)*(r+1) - (r*r)
        if tot > t:
            print "Case #" + str((i+1)) + ": " + str(count)
            break
        else:
            count += 1
            r += 2
