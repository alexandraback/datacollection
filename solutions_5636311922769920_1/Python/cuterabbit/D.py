import sys
inp = open("D-large.in", "r")
sys.stdout = open("D-large-out.txt", "w")
def f():
    [K, C, S] = [int(c) for c in inp.readline().split()]
    if C*S<K:
        return "IMPOSSIBLE"
    current = 0
    ans = []
    for i in range(1, K+1):
        current = current * K + i - 1
        if i % C == 0:
            ans.append(current)
            current = 0    
    if K % C > 0:
        ans.append(current)
    return " ".join([str(i+1) for i in ans])
T = int(inp.readline())
for i in range(T):
    print("Case #" + str(i+1) + ": " + f())