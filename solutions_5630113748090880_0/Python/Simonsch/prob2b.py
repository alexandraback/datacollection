import sys


T = int(sys.stdin.readline())
for t in range(1, T+1):
    N = int(sys.stdin.readline())
    all_heights = []
    for i in range(0, 2*N-1):
        line = sys.stdin.readline()
        line = line.rstrip()
        all_heights.extend(map(int, line.split(" ")))
    y = []
    all_heights.sort()
    all_heights.append(max(all_heights)+1)
    c = all_heights[0]
    count = 0
    for i in range(0, len(all_heights)):
        if all_heights[i] != c:
            if (count % 2 == 1):
                y.append(c)
            c = all_heights[i]
            count = 1
        else:
            count += 1
    print("Case #{}: ".format(t), end="")
    print(" ".join(map(str, y))) 

