# -*- coding: utf-8 -*-


def solve2(c, j):
    n = len(c)
    diff = 0 # -1 if c < j, 0 if c == j, 1 if c > j
    rc = ""
    rj = ""
    ret = 0
    for i in range(n-1, -1, -1):
        ci = c[i]
        ji = j[i]
        rci = ci
        rji = ji
        if ci == "?":
            if ji == "?":
                if diff == -1:
                    rci = "9"
                    rji = "0"
                elif diff == 0:
                    rci = "0"
                    rji = "0"
                else: # diff == 1
                    rci = "0"
                    rji = "9"
            else:
                if diff == -1:
                    rci = "9"
                elif diff == 0:
                    rci = ji
                else: # diff == 1
                    rci = "0"
        elif ji == "?":
            if diff == -1:
                rji = "0"
            elif diff == 0:
                rji = ci
            else: # diff == 1
                rji = "9"
        else:
            if diff == 0:
                if int(ci) < int(ji):
                    diff = -1
                elif int(ci) > int(ji):
                    diff = 1
        rc = rci + rc
        rj = rji + rj
    return rc + " " + rj #rc.zfill(n) + " " + rj.zfill(n)

# def adiff(a1, a2):
#     r = [None] * len(a1)
#     for i in range(len(a1)-1, -1, -1):
#         r[i] = (a1[i] - a2[i]) if (a1[i] != None and a2[i] != None) else None
#     return r


def all_scores(pattern):
    q = [""]
    for c in pattern:
        if c == None:
            q2 = []
            for i in range(10):
                q3 = []
                while len(q) > 0:
                    p = q.pop()
                    r = p + str(i)
                    q2.append(r)
                    q3.append(p)
                q = q3
            q = q2
        else:
            q2 = []
            while len(q) > 0:
                p = q.pop()
                p += str(c)
                q2.append(p)
            q = q2
    return q


def solve(c, j):
    ac = [int(i) if i != "?" else None for i in c]
    aj = [int(i) if i != "?" else None for i in j]
    cs = all_scores(ac)
    js = all_scores(aj)
    closest_scores = float("inf")
    closest_c = 0
    closest_j = 0
    for ci in cs:
        for ji in js:
            ici = int(ci)
            iji = int(ji)
            diff = abs(ici - iji)
            if diff < closest_scores:
                closest_c = ici
                closest_j = iji
                closest_scores = diff
            elif diff == closest_scores:
                if ici < closest_c:
                    closest_c = ici
                    closest_j = iji
                elif ici == closest_c and iji < closest_j:
                    closest_j = iji
    return str(closest_c).zfill(len(c)) + " " + str(closest_j).zfill(len(j))




t = int(input())
for i in range(1,t+1):
    c, j = input().split()
    print("Case #" + str(i) + ": " + solve(c, j))
