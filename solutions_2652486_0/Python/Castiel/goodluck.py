import time
import math
from itertools import combinations

stime = time.time()

data = [[222, 8], [223, 12], [224, 16], [225, 20], [232, 12], [233, 18], [234, 24], [235, 30], [242, 16], [243, 24], [244, 32], [245, 40], [252, 20], [253, 30], [254, 40], [255, 50], [322, 12], [323, 18], [324, 24], [325, 30], [332, 18], [333, 27], [334, 36], [335, 45], [342, 24], [343, 36], [344, 48], [345, 60], [352, 30], [353, 45], [354, 60], [355, 75], [422, 16], [423, 24], [424, 32], [425, 40], [432, 24], [433, 36], [434, 48], [435, 60], [442, 32], [443, 48], [444, 64], [445, 80], [452, 40], [453, 60], [454, 80], [455, 100], [522, 20], [523, 30], [524, 40], [525, 50], [532, 30], [533, 45], [534, 60], [535, 75], [542, 40], [543, 60], [544, 80], [545, 100], [552, 50], [553, 75], [554, 100], [555, 125]]

input = open("goodluck.in" , "r")
output = open("goodluck.out" , "w")
T = int(input.readline())
[R, N, M, K] = [int(x) for x in input.readline().split(" ")]

print "Case #1:"
output.write("Case #1:\n")

for i in range(1, R + 1):

    P = [int(x) for x in input.readline().split(" ")]

    poss = []

    for j in data:
        check = 0
        for k in P:
            if j[1]%k == 0:
                check = check + 1
        if check == K:
            poss.append(j[0])

    ans = poss[0]
    
    print ans
    output.write(str(ans) + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
