import sys

def f(line):
    if len(line) < 2:
        return line
    pivot = max(line)
    results = []
    for i in range(0, len(line)):
        if line[i] == pivot:
            results.append(pivot + f(line[:i]) + line[(i+1):])
    return max(results)

T = int(sys.stdin.readline())
for t in range(1, T+1):
    line = sys.stdin.readline()
    line = line.rstrip()
    print("Case #{}: ".format(t), end="")
    print(f(line)) 

