
def solve(E, R, N, V):
    dp = []
    dp.append([0 for i in range(E+1)])

    for v in V:
        newrow = [0 for i in range(E+1)]
        for i in range(E+1):
            for j in range(0, i+1):
                spent = i-j
                newenergy = min(i-spent+R, E)
                gain = spent*v
                newrow[newenergy] = max(dp[-1][i] + gain,
                                        newrow[newenergy])
        dp.append(newrow)

    #print dp

    return max(dp[-1])



inp = raw_input()
T = int(inp)
for i in range(1,T+1):
    inp = raw_input()
    E, R, N = map(int, inp.split(' '))
    inp = raw_input()
    V = map(int, inp.split(' '))
    answer = solve(E, R, N, V)
    print "Case #" + str(i) + ": " + str(answer)
