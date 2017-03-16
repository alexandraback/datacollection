import sys

def score(cakes):
    return cakes.count('+')

def toggle(cake):
    return '-' if cake == '+' else '+'

def flip(cakes):
    cakes = [toggle(c) for c in cakes][::-1]
    return cakes

def flipi(cakes, i):
    first = flip(cakes[0:i])
    last = cakes[i:]
    return first + last

def last_cake(cakes, i):
    for i in range(i, len(cakes)):
        if cakes[i] == '-':
            return i

case = 0
for line in sys.stdin:
    if case == 0:
        case += 1
        continue
    
    output = "Case #%d: " % case
    pancakes = list(line.rstrip('\n'))
    count = len(pancakes)

    flips = 1 if pancakes[len(pancakes) - 1] == '-' else 0

    prev = None
    for p in pancakes:
        if not prev is None:
            if not p == prev:
                flips += 1
        prev = p

    output += str(flips)

    print output
    case += 1
