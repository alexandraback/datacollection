#!/usr/bin/python2

def selectNext2(avail2, curstar):
    for i in avail2:
        if i[1] <= curstar:
            return i[0]
    return None

def selectNext1(star1, avail1, diff, curstar):
    for i in diff:
        if (i, star1[i]) in avail1 and star1[i] <= curstar:
            return i
    return None

def greedy(star1, star2):
    diff = []
    for i in range(len(star1)):
        #diff.append((star2[i] - star1[i], i))
        diff.append((star2[i], i))
    #diff = sorted(diff, key=lambda e: e[0])
    diff = sorted(diff, key=lambda e: e[0], reverse=True)
    diff = [p[1] for p in diff]

    avail1 = set()
    avail2 = set()
    for i in range(len(star2)):
        avail2.add((i, star2[i]))
    for i in range(len(star1)):
        avail1.add((i, star1[i]))

    curstar = 0
    step = 0
    left = len(star1)
    while left:
        next = selectNext2(avail2, curstar)
        if next != None:
            if (next, star1[next]) not in avail1:
                curstar += 1
            else:
                curstar += 2
                avail1.remove((next, star1[next]))
            avail2.remove((next, star2[next]))
            left -= 1
        else:
            next = selectNext1(star1, avail1, diff, curstar)
            if next != None:
                curstar += 1
                avail1.remove((next, star1[next]))
            else:
                return None
        step += 1
    return step

if __name__ == "__main__":

    f = open('B-large.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d:" % (t + 1),

        star1 = []
        star2 = []
        n = int(f.readline().strip())
        for i in range(1, n + 1):
            a, b = f.readline().split()
            star1.append(int(a))
            star2.append(int(b))

        ans = greedy(star1, star2)
        if ans == None:
            print "Too Bad"
        else:
            print ans
