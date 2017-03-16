file = open("dijkstra.in", "r")
file2 = open("dijkstra.out", "w")

t = int(file.readline())

m = [[0 for i in range(5)] for j in range(5)]

m[1][1] = 1
m[1][2] = 2
m[1][3] = 3
m[1][4] = 4
m[2][1] = 2
m[2][2] = -1
m[2][3] = 4
m[2][4] = -3
m[3][1] = 3
m[3][2] = -4
m[3][3] = -1
m[3][4] = 2
m[4][1] = 4
m[4][2] = 3
m[4][3] = -2
m[4][4] = -1


def mu(a, b):
    x = int(a / abs(a))
    y = int(b / abs(b))
    return x * y * m[abs(a)][abs(b)]


def run(l, x, code, t):
    foundi = -1
    first = {}
    p = 1
    count = 0
    while p not in first and count < x:
        first[p] = count
        for i in range(l):
            p = mu(p, code[i])
            if p == 2 and foundi == -1:
                foundi = i + count * l
        count += 1
    if foundi == -1:
        file2.write("Case #" + str(t) + ": NO\n")
    else:
        if count < x:
            cl = count - first[p]
            firstp = first[p]
            prod = p
            alright = True
        else:
            alright = False
        foundk = -1
        pf = []
        p = 1
        count = 0
        while p not in pf and count < x:
            for i in range(l):
                p = mu(code[l-1-i], p)
                if p == 4 and foundk == -1:
                    foundk = (x - count) * l - i - 1
            count += 1
        if not foundk or foundi >= foundk:
            file2.write("Case #" + str(t) + ": NO\n")
        else:
            if not alright or count == x:
                p = 1
                for i in range(x):
                    for j in range(l):
                        p = mu(p, code[j])
                if p == -1:
                    file2.write("Case #" + str(t) + ": YES\n")
                else:
                    file2.write("Case #" + str(t) + ": NO\n")
            else:
                rest = (x * l - firstp) % cl
                for i in range(rest):
                    for i in range(l):
                        prod = mu(prod, code[i])
                if prod == -1:
                    file2.write("Case #" + str(t) + ": YES\n")
                else:
                    file2.write("Case #" + str(t) + ": NO\n")

for i in range(t):
    lx = file.readline().split()
    l = int(lx[0])
    x = int(lx[1])
    c = file.readline().strip()
    code = []
    for y in c:
        if y == "i":
            code.append(2)
        elif y == "j":
            code.append(3)
        else:
            code.append(4)
    run(l, x, code, i+1)
