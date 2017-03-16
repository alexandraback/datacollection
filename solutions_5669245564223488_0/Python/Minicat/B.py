import itertools
import math

f_in = open("B-small-attempt4.in", 'r')
f_out = open("B-small4.out", 'w')


def get_int():
    return int(f_in.readline().rstrip())

# For each thing in trains, pre-process it.
def preprocess(trains):
    new = []
    while len(trains) > 0:
        piece = trains.pop()
        if len(piece) < 3:
            if len(piece) == 2 and piece[0] == piece[1]:
                new.append(piece[0])
            else:
                new.append(piece)
            continue
        
        start = piece[0]
        end = piece[-1]
        middle = piece[1:-1]


        
        # Trim from start and end to remove repeats
        while len(middle) > 0 and middle[0] == start:
            middle = middle[1:]
        while len(middle) > 0 and middle[-1] == end:
            middle = middle[:-1]

        if len(middle) > 0 and start == end:
            return ["BAD"]

        if len(middle) > 0:
            newmiddle = middle[0]
            for letter in middle:
                if letter != newmiddle [-1]:
                    if letter in newmiddle:
                        return ["BAD"]
                newmiddle = newmiddle + letter
            middle = newmiddle

        # Now check - what letters are left in the middle?
        # For each of these letters
        for l in middle:
            # Now look in each of the other trains
            for train in new + trains:
                if l in train:
                    # Bad! Impossible now
                    return ["BAD"]
        # Done preprocessing train piece

        if len(middle) == 0 and start == end:
            new.append(start)
        else:
            new.append(start+end)
    return new


TR = "trains"
LE = "letters"

def get_groups(trains):
    # First, divide into groups by shared letters.
    groups = []

    while len(trains) > 0:
        curr = trains.pop()
        group = {TR: [curr], LE: set([x for x in curr])}
        change = True
        while change:
            change = False
            for train in trains:
                flag = False
                for l in train:
                    if l in group[LE]:
                        flag = True
                if flag:
                    group[TR].append(train)
                    group[LE].update(set([x for x in train]))
                    trains.remove(train)
                    change = True
        groups.append(group)

    return groups


def valid(way):
    a = way[0]
    i = 1
    while i < len(way):
        b = way[i]
        if a[-1] != b[0]:
            return False
        a = b
        i += 1

    # Now condense and see if theres any repeats
    new = way[0][0]
    for letter in ''.join(way):
        if letter != new[-1]:
            if letter in new:
                return False
            new = new + letter

    zz = set()

    for letter in new:
        zz.add(letter)

    if len(zz) != len(new):
        return False
        print "MEOW"
    
    return True


def solve(group):
    ways = 0
    letters = group[LE]
    trains = group[TR]

    # Draw out connections - directed graph.
    c = {}
    for i in range(0, len(trains)):
        c[i] = []
        for j in range(0, len(trains)):
            if trains[i][-1] == trains[j][0] and i != j:
                c[i].append(j)

    print c

    # Brute force? Enumerate ways
    for way in itertools.permutations(trains):
        if valid(way):
            ways += 1

    return ways

T = get_int()

for i in range(1, T + 1):

    N = get_int()

    trains = f_in.readline().rstrip().split()

    trains2 = preprocess(trains)

    print trains2

    ways = -1
    if trains2[0] == "BAD":
        ways = 0
    else:
        groups = get_groups(trains2)
        ways = math.factorial(len(groups)) % 1000000007
        for group in groups:
            ways = ways * solve(group) % 1000000007
        
    print "Case #{1}: {0}".format(ways, i)
    f_out.write("Case #{1}: {0}\n".format(ways, i))











f_in.close()
f_out.close()
