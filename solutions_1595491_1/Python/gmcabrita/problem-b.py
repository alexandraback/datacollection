def check(l):
    v = list(l)
    v.pop(0)  # we don't need the number of googlers
    s = v.pop(0)
    p = v.pop(0)

    sure = list()
    probable = list()

    for i in v:
        if i >= 3 * p - 2 or p == 0:
            sure.append(i)

    for i in v:
        if i not in sure and i >= 3 * p - 4 and (p is not 1 or i > 0):
            probable.append(i)

    return len(sure) + min(len(probable), s)

c = input()
for i in range(c):
    l = [int(x) for x in raw_input().split()]
    r = check(l)
    print "Case #" + str(i + 1) + ": " + str(r)
