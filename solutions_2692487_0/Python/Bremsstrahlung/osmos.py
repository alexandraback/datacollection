input = open("A-small-attempt0.in")
output= open("output.out","w")

cases = input.readlines()[1:]
t = 0
while len(cases):
    t += 1
    s,_ = map(int,cases.pop(0).strip().split())
    m = map(int,cases.pop(0).strip().split())
    m.sort()
    n = 0
    sol = []
    for i in range(len(m)):
        if m[i] < s:
            s += m[i]
        else:
            sol.append(n + len(m) - i)
            if s > 1:
                while s <= m[i]:
                    n += 1
                    s += s - 1
                s += m[i]
            else:
                break
        if i + 1 == len(m):
            sol.append(n)
    sol.sort()
    print "Case #{}: {}".format(t,sol[0])
    output.write("Case #{}: {}\n".format(t,sol[0]))

input.close()
output.close()
