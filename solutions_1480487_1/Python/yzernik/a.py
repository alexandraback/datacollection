from collections import deque as Queue


def solve(N, S):
    r = sorted(S)
    u = [0 for i in range(len(S))]
    points = sum(S)
    for i in range(len(r)-1):
        diff = r[i+1] - r[i]
        if diff > 0:
            points_used = float(min(points, diff*(i+1)))
            points -= points_used
            for j in range(i+1):
                r[j] += points_used/(i+1)
                u[j] += points_used/(i+1)
                    
    for i in range(len(r)):
        r[i] += float(points)/len(r)
        u[i] += float(points)/len(r)

    percents = [(n/sum(u))*100 for n in u]

    print_o = [o[0] for o in sorted(list(enumerate(S)), key=lambda x: x[1])]
    result = ''
    for i in range(len(print_o)):
        x = print_o.index(i)
        result += ' ' + str(percents[x])
    
    return result


inp = raw_input()
T = int(inp)
for t in range(1,T+1):
    inp = raw_input()
    S = map(int,inp.split(' '))[1:]
    N = len(S)
    answer = solve(N, S)
    print "Case #" + str(t) + ":" + str(answer)
