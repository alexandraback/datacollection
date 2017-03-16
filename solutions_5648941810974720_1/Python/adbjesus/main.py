L = ["Z", "ON", "W", "HR", "U", "F", "X", "V", "G", "I"]
LC = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def solve():
    global L
    global L2

    S = [s for s in input()]
    N = []

    # Solve one letters
    for i in range(len(L)):
        if len(L[i])==1:
            while L[i] in S:
                N.append(str(i))
                for c in LC[i]:
                    S.remove(c)

    for i in range(len(L)):
        if len(L[i])==2:
            while L[i][0] in S and L[i][1] in S:
                N.append(str(i))
                for c in LC[i]:
                    S.remove(c)



    return ''.join(sorted(N))


T = int(input())
for t in range(1,T+1):
    print("Case #%d: %s" % (t,solve()))
