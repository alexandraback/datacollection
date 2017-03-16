__author__ = 'archeg'

def solve(n, m, t):
    for i in range(n):
        for j in range(m):
            c = t[i][j]
            resultRow = all(x <= c for x in t[i])
            resultCol = True
            for k in range(n):
                if t[k][j] > c:
                    resultCol = False
            if not resultRow and not resultCol:
                return "NO"
    return "YES"

def run():
    fi = open('lawnmover.in', 'r')
    input = fi.readlines()
    t = int(input[0])
    problems = []
    index = 1
    for i in range(t):
        n, m = [int(x) for x in input[index].split()]
        t = []
        index += 1
        for j in range(n):
            t.append([int(x) for x in input[index].split()])
            index+=1
        problems.append((n, m, t))

    output = []
    testCaseN = 1
    for problem in problems:
        n,m,t = problem
        output.append("Case #%i: %s\n" % (testCaseN, solve(n, m, t)))
        testCaseN += 1

    with open('lawnmover.out', 'w') as fo:
        fo.writelines(output)
    fo.close()

def generateAndCheck():
    import random
    a = []
    for i in range(100):
        a.append([int(random.random() * 100) for x in range(100)])
    print solve(100, 100, a)

run()

