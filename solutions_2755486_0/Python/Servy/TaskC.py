
import sys

tests = int(sys.stdin.readline())

def check(wall, w, e, s):
    return min(wall[5000 + w*2:5000 + e*2]) < s

def update(wall, w, e, s):
    for i in range(w*2, e * 2 + 1):
        if wall[5000+i] < s:
            wall[5000+i] = s

for t in range(tests):
    n = int(sys.stdin.readline())
    clans = []
    attacks = []
    wall = [0 for i in range(10000)]
    for i in range(n):
        (di, ni, wi, ei, si, delta_di, delta_pi, delta_si) = map(int, sys.stdin.readline().split())
        clans.append((di, ni, wi, ei, si, delta_di, delta_pi, delta_si))
        
        for j in range(ni):
            attacks.append((di + delta_di * j, wi + delta_pi * j, ei + delta_pi * j, si + delta_si * j))
    
    attacks.sort(key=lambda x: x[0])
    attacks.append((1000000, 0, 0, 0))
    
    intervals = []
    count = 1    
    for a in range(len(attacks) - 1):
        if (attacks[a][0] == attacks[a+1][0]):
            count += 1
        else:
            intervals.append(count)
            count = 1
    
    res = 0
    cur = 0    
    for i in intervals:
        for a in range(cur, cur + i):
            if check(wall, attacks[a][1], attacks[a][2], attacks[a][3]):
                res += 1
        for a in range(cur, cur + i):
            update(wall, attacks[a][1], attacks[a][2], attacks[a][3])
        cur += i
    print("Case #%d: %d" % (t + 1, res))
