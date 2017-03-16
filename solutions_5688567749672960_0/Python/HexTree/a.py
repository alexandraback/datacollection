dist = dict()
tens = [int('1' + '0'*j) for j in range(16)]

def rev(n):
    string = str(n)
    string = string[::-1]
    while string[0] == '0':
        string = string[1:]
    return int(string)

def distance(start, goal):
    global dist
    global tens
    if (start, goal) in dist:
        return dist[(start, goal)]
    if start == goal:
        return 0
    a, b = str(start), str(goal)
    d = 0
    if len(a) == len(b):
        if len(a) == 1:
            d = goal-start
        elif start in tens:
            if b[-1] == '0':
                d = distance(start, goal-1) + 1
            else:
                middle = len(b)/2
                right = b[middle:]
                ri = int(right)

                left = b[:middle]

                if left == '1' + '0'*(len(left)-1):
                    d = ri

                else:
                    left = left[::-1]
                    d = ri
                    d += 1
                    l = int(left)
                    d += (l-1)
        else:
            print "unknown1!"
    elif len(b) > len(a) and start in tens:
        if goal == 10*start:
            d = distance(start, goal-1) + 1
        else:
            d = distance(start, 10*start) + distance(10*start, goal)
    else:
        print start, goal, "unknown2!", (start in tens)
    dist[(start, goal)] = d
    print start, goal, d
    return d


g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        N = int(f.readline())

        if N == 1:
            g.write("Case #%d: %d\n" % (r+1, 1))
            continue

        result = distance(1, N) + 1

        g.write("Case #%d: %d\n" % (r+1, result))
f.close()
g.close()