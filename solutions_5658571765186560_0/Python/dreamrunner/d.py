def solve(x, r, c):
    if r*c % x != 0:
        return True
    if r == 1:
        return x > 2
    return x >= min(r, c) * 2

test = int(input())

for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")
    ins = input().split(" ")
    X = int(ins[0])
    R = int(ins[1])
    C = int(ins[2])
    if R > C:
        R, C = C, R
    if solve(X, R, C):
        print("RICHARD")
    else:
        print("GABRIEL")
