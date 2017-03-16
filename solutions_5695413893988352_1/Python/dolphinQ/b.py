import sys, math
def rs():
    return sys.stdin.readline().strip()
def ri():
    return int(sys.stdin.readline().strip())
def ras():
    return list(sys.stdin.readline().strip())
def rai():
    return map(int,sys.stdin.readline().strip().split())
def raf():
    return map(float,sys.stdin.readline().strip().split())



# def slv(s1,s2, rs, prefix=""):
#     if len(s1) == 0:
#         return rs.append((prefix, prefix))

#     a,b = s1[0], s2[0]
#     if a == b:
#         if a != "?":
#             slv(s1[1:], s2[1:], rs, prefix+a)
#         else:
#             pass
#     else:
#         if a == "?":
#             for i in xrange(10):
#                 slv(str(i) + s1[1:], s2, rs, pre)
#         elif b == "?":
#             for i in xrange(10):
#                 slv(s1, str(i)+s2[1:])


def res(s1,s2):
    if int(s1[0] > s2[0]): return s1.replace("?","0"), s2.replace("?","9")
    else: return s1.replace("?","9"), s2.replace("?","0")


def solve():
    s1, s2 = rs().split(" ")
    l = len(s1)
    start = 0
    results = []
    prefix = ""
    for i in xrange(l):
        a,b = s1[i], s2[i]
        if a == b:
            if a == "?" and b == "?":
                r1,r2 = res("0" + s1[i+1:], "1" + s2[i+1:])
                results.append((prefix+r1, prefix+r2))
                r1,r2 = res("1" + s1[i+1:], "0" + s2[i+1:])
                results.append((prefix+r1, prefix+r2))
                prefix += "0"
            else:
                prefix += a
        else:
            if a == "?":
                if b == "9":
                    r1,r2 = res("8" + s1[i+1:], s2[i:])
                    results.append((prefix+r1, prefix+r2))
                elif b == "0":
                    r1,r2 = res("1" + s1[i+1:], s2[i:])
                    results.append((prefix+r1, prefix+r2))
                else:
                    ib = int(b)
                    r1,r2 = res(str(ib+1) + s1[i+1:], s2[i:])
                    results.append((prefix+r1, prefix+r2))
                    r1,r2 = res(str(ib-1) + s1[i+1:], s2[i:])
                    results.append((prefix+r1, prefix+r2))
                prefix += b
            elif b == "?":
                if a == "9":
                    r1,r2 = res(s1[i:], "8"+s2[i+1:])
                    results.append((prefix+r1, prefix+r2))
                elif a == "0":
                    r1,r2 = res(s1[i:], "1" + s2[i+1:])
                    results.append((prefix+r1, prefix+r2))
                else:
                    ia = int(a)
                    r1,r2 = res(s1[i:], str(ia+1) + s2[i+1:])
                    results.append((prefix+r1, prefix+r2))
                    r1,r2 = res(s1[i:], str(ia-1) + s2[i+1:])
                    results.append((prefix+r1, prefix+r2))
                prefix += a
            else:           
                r1,r2 = res(s1[i:], s2[i:])
                results.append((prefix+r1, prefix+r2))
                break
    if len(prefix) == l:
        results.append((prefix, prefix))

    def cmp(a,b):
        return (a[2]-b[2]) or (int(a[0]) - int(b[0])) or (int(a[1]) - int(b[1]))

    results = map(lambda x: (x[0], x[1], abs(int(x[0]) - int(x[1]))), results)
    results = sorted(results, cmp=cmp)
    return results[0][0] + " " + results[0][1]


T = ri()
result = []
for x in xrange(T):
    result.append("Case #%s: %s"%((x+1), solve()))
with open("./hard.out", "w+") as f:
    f.write("\n".join(result))












