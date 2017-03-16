def nval(name, n):
    nval = 0
    for i in range(0, len(name)):
        consn = 0
        for j in range(i, len(name)):
            if name[j] not in 'aeiou':
                consn += 1
            elif consn < n:
                consn = 0
            if consn >= n:
                nval += 1
    return nval

t = int(input())
for i in range(1, t+1):
    inp = input()
    name = inp.split()[0]
    n = int(inp.split()[1])
    print("Case #%i: %i" % (i, nval(name, n)))
