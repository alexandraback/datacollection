from math import ceil
cases = int(raw_input().strip())

for case in range(1, cases+1):
    line = raw_input().strip()
    R, C, W = map(int, line.split(" "))
    score = ((C/W)*R + W-1) if (C%W <= 0) else ((C/W)*R + W)
    print "Case #"+str(case)+": "+str(score)
