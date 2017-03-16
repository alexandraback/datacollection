from sys import stdin, stdout

def solve(S):
    final = []
    for s in S:
        if not final:
            final.append(s)
        elif s >= final[0]:
            final.insert(0, s)
        else:
            final.append(s)

    return "".join(final)



T = int(stdin.readline())

for t in range(T):
    S = stdin.readline().strip()

    result = solve(S)

    stdout.write("Case #%d: %s\n"%(t+1, result))