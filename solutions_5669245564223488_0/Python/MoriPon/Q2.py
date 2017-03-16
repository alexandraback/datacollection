import itertools
from math import factorial


def check(per):
    word = ''
    for i in per:
        word += trains2[i]
    counts = [0]*26
    offset = 97
    a = word[0]
    t = ord(a) - offset
    counts[t] = 1
    for i in range(len(word)-1):
        a = word[i]
        b = word[i+1]
        if not a == b:
            t = ord(b) - offset
            if not counts[t] == 0:
                return 0
            counts[t] = 1
    return 1

def minimize(word):
    mini = word[0]
    for i in range(len(word)-1):
        a = word[i]
        b = word[i+1]
        if not a == b:
            mini += b
    return mini


rfile = file('Q2small.in', 'r')
wfile = file('Q2small.out', 'w')
num_of_cases = int(rfile.readline().strip())
for case in range(1, num_of_cases+1):
    print case
    #write result
    N = int(rfile.readline().strip())
    inp = rfile.readline().strip().split()
    trains1 = []
    for t in inp:
        trains1.append(minimize(t))
    trains1.sort()
    trains2 = trains1
    ways = 0
    multi = 1
    letter = 97
    maxi = 26+97
    while letter <= maxi:
        first = [t for t in trains2 if t[0] == chr(letter)]
        last = [t for t in trains2 if t[-1] == chr(letter)]
        both = [t for t in first if t in last]
        if len(both) > 1:
            trains2 = [t for t in trains2 if not t in both]
            wo = ''
            for w in both:
                wo += w
            multi *= factorial(len(both))
            trains2.append(wo)
        letter += 1
    N = len(trains2)
    print 'N=',N
    for per in itertools.permutations(range(N)):
        ways += check(per)
    to_write = str(int(ways*multi))
    wfile.write('Case #'+str(case)+': '+to_write+'\n')
