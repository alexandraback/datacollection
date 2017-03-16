def case(n):
    a, b, c, l = map(int, input().split())
    ab, bc, ac = dict(), dict(), dict()
    output = ""
    s = 0
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            for k in range(1, c + 1):
                if not (i, j) in ab:
                    ab[(i, j)] = 0
                if not (j, k) in bc:
                    bc[(j, k)] = 0
                if not (i, k) in ac:
                    ac[(i, k)] = 0
                #print(ab, bc, ac)
                if ab[(i, j)] < l and bc[(j, k)] < l and ac[(i, k)] < l:
                    output += " ".join(map(str, [i, j, k])) + "\n"
                    s += 1
                    ab[(i, j)] += 1
                    bc[(j, k)] += 1
                    ac[(i, k)] += 1
    print("Case #" + str(n) + ": " + str(s))
    print(output, end="")

t = int(input())
for i in range(1, t + 1):
    case(i)