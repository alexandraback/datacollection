import sys

d = [0] * 10
d[0] = { "Z" : 1, "E" : 1, "R" : 1, "O" : 1 }
d[1] = { "O" : 1, "N" : 1, "E" : 1 }
d[2] = { "T" : 1, "W" : 1, "O" : 1 }
d[3] = { "T" : 1, "H" : 1, "R" : 1, "E" : 2 }
d[4] = { "F" : 1, "O" : 1, "U" : 1, "R" : 1 }
d[5] = { "F" : 1, "I" : 1, "V" : 1, "E" : 1 }
d[6] = { "S" : 1, "I" : 1, "X" : 1 }
d[7] = { "S" : 1, "E" : 2, "V" : 1, "N" : 1 }
d[8] = { "E" : 1, "I" : 1, "G" : 1, "H" : 1, "T" : 1 }
d[9] = { "N" : 2, "I" : 1, "E" : 1 }

def solve(counts, acc, t):
    if t > 9:
        return None
    s = 0
    for c in counts.keys():
        s += counts[c]
    if s == 0:
        return acc
    can_subtract = True
    for c in d[t].keys():
        if c not in counts or counts[c] < d[t][c]:
            can_subtract = False
    if can_subtract:
        tmp_counts = counts.copy()
        for c in d[t].keys():
            tmp_counts[c] -= d[t][c]
        ans = solve(tmp_counts, acc + str(t), t)
        if ans is None:
            ans = solve(counts, acc, t + 1)
        return ans
    else:
        return solve(counts, acc, t + 1)

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    l = sorted(l)
    counts = {}
    s = len(l)
    for c in l:
        if c not in counts:
            counts[c] = 0
        counts[c] += 1
    ans = solve(counts, "", 0)
    print("Case #%d: %s" % (i + 1, ans))

