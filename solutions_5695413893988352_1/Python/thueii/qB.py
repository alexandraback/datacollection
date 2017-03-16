import sys

ZEROS = "000000000000000000"

def solve(c1, c2, j1, j2):
    if len(c2) <= 0 or len(j2) <= 0:
        return (c1, j1)
    if c2[0] == '?' and j2[0] == '?':
        if c1 > j1:
            return solve(c1 * 10, c2[1:], j1 * 10 + 9, j2[1:])
        elif c1 < j1:
            return solve(c1 * 10 + 9, c2[1:], j1 * 10, j2[1:])
        else:
            t = []
            t.append(solve(c1 * 10, c2[1:], j1 * 10, j2[1:]))
            t.append(solve(c1 * 10 + 1, c2[1:], j1 * 10, j2[1:]))
            t.append(solve(c1 * 10, c2[1:], j1 * 10 + 1, j2[1:]))
            s = None
            for t2 in t:
                if s is None:
                    s = t2
                if abs(t2[0] - t2[1]) < abs(s[0] - s[1]):
                    s = t2
                elif abs(t2[0] - t2[1]) == abs(s[0] - s[1]):
                    if t2[0] < s[0]:
                        s = t2
                    elif t2[0] == s[0] and t2[1] < s[1]:
                        s = t2
            return s
    elif c2[0] == '?' and j2[0] != '?':
        if c1 > j1:
            return solve(c1 * 10, c2[1:], j1 * 10 + int(j2[0]), j2[1:])
        elif c1 < j1:
            return solve(c1 * 10 + 9, c2[1:], j1 * 10 + int(j2[0]), j2[1:])
        else:
            t = []
            t.append(solve(c1 * 10 + int(j2[0]), c2[1:], j1 * 10 + int(j2[0]), j2[1:]))
            if int(j2[0]) > 0:
                t.append(solve(c1 * 10 + int(j2[0]) - 1, c2[1:], j1 * 10 + int(j2[0]), j2[1:]))
            if int(j2[0]) < 9:
                t.append(solve(c1 * 10 + int(j2[0]) + 1, c2[1:], j1 * 10 + int(j2[0]), j2[1:]))
            s = None
            for t2 in t:
                if s is None:
                    s = t2
                if abs(t2[0] - t2[1]) < abs(s[0] - s[1]):
                    s = t2
                elif abs(t2[0] - t2[1]) == abs(s[0] - s[1]):
                    if t2[0] < s[0]:
                        s = t2
                    elif t2[0] == s[0] and t2[1] < s[1]:
                        s = t2
            return s
    elif c2[0] != '?' and j2[0] == '?':
        if c1 > j1:
            return solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10 + 9, j2[1:])
        elif c1 < j1:
            return solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10, j2[1:])
        else:
            t = []
            t.append(solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10 + int(c2[0]), j2[1:]))
            if int(c2[0]) > 0:
                t.append(solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10 + int(c2[0]) - 1, j2[1:]))
            if int(c2[0]) < 9:
                t.append(solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10 + int(c2[0]) + 1, j2[1:]))
            s = None
            for t2 in t:
                if s is None:
                    s = t2
                if abs(t2[0] - t2[1]) < abs(s[0] - s[1]):
                    s = t2
                elif abs(t2[0] - t2[1]) == abs(s[0] - s[1]):
                    if t2[0] < s[0]:
                        s = t2
                    elif t2[0] == s[0] and t2[1] < s[1]:
                        s = t2
            return s
    elif c2[0] != '?' and j2[0] != '?':
        return solve(c1 * 10 + int(c2[0]), c2[1:], j1 * 10 + int(j2[0]), j2[1:])

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    tokens = l.split(" ")
    ans = solve(0, tokens[0], 0, tokens[1])
    ans1 = str(ans[0])
    ans1 = ZEROS[:(len(tokens[0])-len(ans1))] + ans1
    ans2 = str(ans[1])
    ans2 = ZEROS[:(len(tokens[1])-len(ans2))] + ans2
    print("Case #%d: %s %s" % (i + 1, ans1, ans2))

