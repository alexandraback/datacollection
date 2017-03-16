#! /usr/bin/python -tt

def solve(name, n):
    voyels = ['a', 'e', 'i', 'o', 'u']
    last_begin = None
    last_consec = 0
    count = 0
    for i, letter in enumerate(name):
        if letter in voyels:
            last_consec = 0
        else:
            last_consec += 1
        if last_consec >= n:
            last_begin = i-n+1
        if last_begin != None:
            count += last_begin+1
    return count


nb_problems = input()
for i in range(nb_problems):
    line = raw_input().split()
    name = line[0]
    n = int(line[1])
    print "Case #" + str(i+1) + ":", solve(name, n)

