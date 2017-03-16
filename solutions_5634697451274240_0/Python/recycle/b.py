import sys

sys.stdin = open("B-small-attempt0.in", "r")
sys.stdout = open("out.txt", "w")

t = int(input())

for i in range(t):
    s = input()
    point = 0
    prev = None
    for c in s:
        if prev is not None and prev != c:
            point += 1
        prev = c
    if prev == '-':
        point += 1
        
    print("Case #%d: %d"%(i+1, point))
    
sys.stdout.close()
