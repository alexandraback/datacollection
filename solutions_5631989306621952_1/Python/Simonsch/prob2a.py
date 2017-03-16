import sys

def f(line):
    if len(line) < 2:
        return line
    pivot = max(line)
    results = []
    for i in range(0, len(line)):
        j = len(line) - i - 1
        if line[j] == pivot:
            results.append(pivot + f(line[:j]) + line[(j+1):])
            break
    return max(results)

sys.setrecursionlimit(1500)
T = int(sys.stdin.readline())
for t in range(1, T+1):
    line = sys.stdin.readline()
    line = line.rstrip()
    print("Case #{}: ".format(t), end="")
    print(f(line)) 

