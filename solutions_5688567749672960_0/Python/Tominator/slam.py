

import sys
def read():
    return sys.stdin.readline().strip()



def reverse_number(n):
    s = str(n)
    return int(s[::-1])

def next_numbers(current):
    return [current+1, reverse_number(current)]

def distance(target):
    Reached = set()
    steps = 1

    Fringe = set([1])

    while True:
        Reached.update(Fringe)
        if target in Reached:
            return steps

        old_fringe = Fringe
        Fringe = set()

        steps += 1
        for number in old_fringe:
            for n in next_numbers(number):
                if n not in Reached:
                    Fringe.add(n)

num_cases = int(read())
for case in xrange(num_cases):
    n = int(read())
    print "Case #%d: %d" % (case+1, distance(n))

