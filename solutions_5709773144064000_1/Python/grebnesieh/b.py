input = open("b.in" , "r")
output = open("b.out" , "w")

def solve(C, F, X):
    if C >= X:
        return X/2
    d = 0
    n = 0
    b = X/(2 + (n * F))
    t = 0
    while d == 0:
        a = b
        b = X/(2 + ((n + 1) * F))
        tn = C/(2 + (n * F))
        if tn + b < a:
            n += 1
            t += tn
        else:
            d = 1
            t += a
    return t

T = int(input.readline())
for i in range(1, T + 1):
    C, F, X = map(float, input.readline().split(" "))
    print "Case #" + str(i) + ": " + str(solve(C, F, X))
    output.write("Case #" + str(i) + ": " + str(solve(C, F, X)) + "\n")
input.close()
output.close()
