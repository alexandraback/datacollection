#!/usr/local/bin/python3
# Codejam ID 6224486
# Run with parameter
# -s for small input
# -l for large input


from GCJ import GCJ

def parse(infile):
    N = GCJ.readint(infile)
    pancakes = GCJ.readintarray(infile)
    return N, pancakes

def solve(data):
    N, pancakes = data
    M = max(pancakes)
    time = M
    special = 0
    count = [0 for i in range(M+1)]
    for x in pancakes:
        count[x] += 1


    for size in range(M,0,-1):
        if count[size] > 0:
            if (special+size) < time:
                time = special+size
            special += count[size]
            if size == 9 and count[size] == 1 and count[8]+count[7]+count[5]+count[4] == 0:
              special += 1
              count[3] += 3
            else:
              half = size//2
              count[half] += count[size]
              if (size % 2) == 1:
                  count[half+1] += count[size]
              else:
                  count[half] += count[size]

    compare = M
    special = 0
    count = [0 for i in range(M+1)]
    for x in pancakes:
        count[x] += 1

    for size in range(M,0,-1):
        if count[size] > 0:
            if (special+size) < compare:
                compare = special+size
            special += count[size]
            half = size//2
            count[half] += count[size]
            if (size % 2) == 1:
                count[half+1] += count[size]
            else:
                count[half] += count[size]
            for size in range(1,M):
              count[size] = count[size+1]

    return min(time,compare)

GCJ('B', solve, parse, None).run()
