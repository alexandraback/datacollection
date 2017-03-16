def check(a, b):
    r = 0

    for i in range(a, b):
        string = str(i)
        recycled = set([i])

        for j in range(len(string)):
            string = string[-1:] + string[:-1]
            integer = int(string)

            if integer > i and a <= integer <= b:
                recycled.add(integer)

        r += len(recycled) - 1

    return r

c = input()
for i in range(c):
    a, b = [int(x) for x in raw_input().split()]
    r = check(a, b)
    print "Case #" + str(i + 1) + ": " + str(r)
