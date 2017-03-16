import sys
import numpy as np
T = int(sys.stdin.readline())
#T = 100
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    p = sys.stdin.readline().strip()
    #pancakes = ''.join(map(lambda x: '+' if x==1 else '-', np.random.randint(2, size=20)))
    N = len(p)
    steps=0

    for i in range(1, N):
        if p[i-1] != p[i]:
            steps+= 1

    if p[0] == '+' and steps % 2 == 1:
        steps += 1
    elif p[0] == '-' and steps % 2 == 0:
        steps += 1
    sys.stdout.write("%d\n" % steps)
