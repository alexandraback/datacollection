infile = open("B-small-attempt2.in", "rU")
outfile = open("B.out", "w")

import itertools

ncases = int(infile.readline())

def valid(string):
    last = ""
    found = []
    
    for s in string:
        if s == last:
            continue

        if s == "" or s not in found:
            found.append(s)
            last = s
            continue

        return False

    return True

def trim(string):
    last = ""
    output = ""

    for s in string:
        if last == "" or last[0] == s:
            if len(last) < 2:
                output += s
                
            last += s

        else:
            last = s
            output += s

    return output

def factorial(n):
    if n < 2:
        return 1

    return n * factorial(n-1)

for case in xrange(1, ncases + 1):
    ncars = int(infile.readline())
    cars = infile.readline().strip().split(" ")

    # Turn triple or more to double letters
    for i in xrange(ncars):
        cars[i] = trim(cars[i])

    counts = {} # How many of each letter there are

    for c in cars:
        for l in c:
            if l not in counts:
                counts[l] = 1

            else:
                counts[l] += 1

    impossible = False
    for c in cars:
        stripped_car = c
        first = stripped_car[0]
        last = stripped_car[-1]

        while len(stripped_car) > 0 and stripped_car[0] == first:
            stripped_car = stripped_car[1:]

        while len(stripped_car) > 0 and stripped_car[-1] == last:
            stripped_car = stripped_car[:-1]


        if len(stripped_car) > 1 and c[0] == c[-1]:
            impossible = True
            break

        last = ""

        index = 0

        while index < len(stripped_car):
            s = stripped_car[index]
            
            if counts[s] > 1:
                char = s
                total = 0

                while index < len(stripped_car) and stripped_car[index] == s:
                    total += 1
                    index += 1

                if total < counts[s]:
                    impossible = True

            else:
               index += 1

    if impossible:
        outfile.write("Case #%d: 0\n" % case)
        continue

    new_cars = []
    doubles = {}
    
    for c in cars:
        if c[0] == c[-1]:
            if c[0] not in doubles:
                doubles[c[0]] = 1

            else:
                doubles[c[0]] += 1

        else:
            new_cars.append(c[0] + c[-1])

    diff_cars = new_cars

    for c in xrange(len(diff_cars)):
        for d in xrange(len(diff_cars)):
            if c != d and (diff_cars[c][0] == diff_cars[d][0] or diff_cars[c][-1] == diff_cars[d][-1]):
                impossible = True

    if impossible:
        outfile.write("Case #%d: 0\n" % case)
        continue

    tuple_cars = []

    for d in doubles:
        tuple_cars.append((d+d, factorial(doubles[d])))


    for d in diff_cars:
        tuple_cars.append((d, 1))
            
    found = True

    while found:
        found = False

        for a in xrange(len(tuple_cars)):
            for b in xrange(a + 1, len(tuple_cars)):
                if tuple_cars[a][0][0] == tuple_cars[b][0][-1]:
                    c = (tuple_cars[b][0] + tuple_cars[a][0], tuple_cars[a][1] * tuple_cars[b][1])

                    ax = tuple_cars[a]
                    bx = tuple_cars[b]
                    tuple_cars.remove(ax)
                    tuple_cars.remove(bx)
                    tuple_cars.append(c)
                    found = True
                    break

                if tuple_cars[a][0][-1] == tuple_cars[b][0][0]:
                    c = (tuple_cars[a][0] + tuple_cars[b][0], tuple_cars[a][1] * tuple_cars[b][1])

                    ax = tuple_cars[a]
                    bx = tuple_cars[b]
                    tuple_cars.remove(ax)
                    tuple_cars.remove(bx)
                    tuple_cars.append(c)
                    found = True
                    break

            if found:
                break
        
    total = factorial(len(tuple_cars))

    for i in tuple_cars:
        total *= i[1]

    outfile.write("Case #%d: %d\n" % (case, total))

infile.close()
outfile.close()
