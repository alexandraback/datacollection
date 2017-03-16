import sys

digits = set([])

def add_seen_digits(i):
    for d in str(i):
        digits.add(d)

def until_seen_all_digits(i):
    cur = i
    add_seen_digits(cur)
    while len(digits) < 10:
        cur += i
        add_seen_digits(cur)
    return cur
    
T = int(sys.stdin.readline())
case = 1
for line in sys.stdin:
    s = line.strip()
    if len(s) > 0:
        i = int(s)
        if i == 0:
            print "Case #{0}:".format(case), "INSOMNIA"
        else:
            digits = set([])
            print "Case #{0}:".format(case), until_seen_all_digits(i)
        case += 1


