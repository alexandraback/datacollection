epi = 1e-10
def collide(pos):
    for i in range(n):
        for j in range(i+1, n):
            iIsRight = (pos & (1 << i)) == 0
            jIsRight = (pos & (1 << j)) == 0
            if not (iIsRight ^ jIsRight) and abs(p[i] + s[i] * (time + epi) - p[j] - s[j] * (time + epi)) < 5:
                return True
    return False

def notcoll(pos):
    return collide(pos)

def expand(pos):
    for i in range(n):
        new = pos ^ (1 << i)
        if not collide(new) and not new in o_pos:
            o_pos.add(new)
            expand(new)

t = input()
for testcase in range(1, t+1):
    n = input()
    s, p = [0] * n, [0] * n
    o = 0
    for i in range(n):
        c, s[i], p[i] = raw_input().split()
        if c == 'L':
            o += 1 << i

    s = map(int, s)
    p = map(int, p)
    o_pos, c_time = set([o]), [0]

    for i in range(n):
        for j in range(i+1, n):
            if s[i] != s[j]:
                time = float(p[i] - p[j] + 5) / (s[j] - s[i])
                if time > 0:
                    c_time.append(time)
                time = float(p[i] - p[j] - 5) / (s[j] - s[i])
                if time > 0:
                    c_time.append(time)

    c_time.sort()
    
    TimeEnded = 'Possible'

    for time in c_time:
        tempo = list(o_pos)
        for pos in tempo:
            if collide(pos):
                o_pos.remove(pos)
        tempo = list(o_pos)
        for pos in tempo:
            expand(pos)
        if not o_pos:
            TimeEnded = time
            break

    print "Case #" + str(testcase) + ": " + str(TimeEnded)

    
