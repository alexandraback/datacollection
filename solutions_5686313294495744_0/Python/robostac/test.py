import math


def addlist(d, v):
    if v in d:
        d[v] += 1
    else:
        d[v] = 1

def solve(N):
    print(N)
    first = {}
    second = {}
    for x in N:
        t = x.split()
        addlist(first,t[0])
        addlist(second, t[1])
    fakef = {}
    fakes = {}
    fakelist = []
    reallist = []
    realf = {}
    reals = {}
    for x in N:
        t = x.split()
        if first[t[0]] == 1:
            addlist(realf, t[0])
            addlist(reals, t[1])
        if second[t[1]] == 1:
            addlist(realf,t[0])
            addlist(reals, t[1])
        if first[t[0]] >= 2 and second[t[1]] >= 2:
            fakelist.append(x)
    f = fakelist[:]
    for x in f:
        t = x.split()
        if t[0] not in realf and t[1] not in reals:
            addlist(realf, t[0])
            addlist(reals, t[1])
            fakelist.remove(x)
    f = fakelist[:]
    for x in f:
        t = x.split()
        if t[0] not in realf or t[1] not in reals:
            addlist(realf, t[0])
            addlist(reals, t[1])
            fakelist.remove(x)
    return str(len(fakelist))


def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


f = open("input.txt")
f = open("C-small-attempt3.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    V = []
    N = [int(x) for x in f.readline().split()]
    for i in range(0,N[0]):
        V.append(f.readline().strip())
    output_res(case, solve(V),outfile)

