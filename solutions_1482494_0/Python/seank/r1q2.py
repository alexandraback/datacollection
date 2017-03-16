#!/usr/bin/env python
#from collections import defaultdict

def recycle(a, b):
    zz = str(a) * 2
    return str(b) in zz

def range_recycle(a, b):
    count = 0
    for i in range(a, b):
        for j in range(i+1, b+1):
            if recycle(i, j):
                count += 1
    return count
def processFile(fname):
    def processCase(f):
        num_levels = int(f.readline().strip("\n"))
        levels = []
        for case in range(num_levels):
            mid = f.readline().strip("\n").split(" ")
            level = map(int, mid) + [0]
            levels.append(level)
        stars = 0
        attempts = 0
        print levels
        while True:
            prev_stars = stars
            levels = [level for level in levels if (level[2] != 2)]
            print sorted(levels, key=lambda x: (x[2], x[1])), stars, attempts, '1st'
            for x in sorted(levels, key=lambda x: (x[2], x[1])):
            
                if x[1] <= stars:
                    stars += 2 - x[2]
                    x[2] = 2
                    attempts += 1
            if stars != prev_stars:
                continue
            print sorted(levels, key=lambda x: (-x[2], -x[1])), stars, attempts, '2nd'
            for x in sorted(levels, key=lambda x: (-x[2], -x[1])):
                if x[2] == 0 and x[0] <= stars:
                    stars += 1
                    x[2] += 1
                    attempts += 1
                    break
            if stars == (2 * num_levels):
                return attempts
            elif stars == prev_stars:
                return 'Too Bad'
    
    with open(fname, "r") as f:
        cases = int(f.readline().strip("\n"))
        output = ""
        for case in range(cases):
            a = processCase(f)
            output += "Case #%d: %s\n" % (case + 1, a)
        print output
    with open("ans"+fname, "w") as f:
        f.write(output)

#processFile("sample.txt")
processFile("B-small-attempt0.in")
#processFile("B-large.in")