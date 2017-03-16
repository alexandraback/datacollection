import sys

if __name__ == "__main__":

    T = int(sys.stdin.readline())

    for case in range(T):
        (X, R, C) = (int(X) for X in sys.stdin.readline().split())
        if (R*C)%X != 0:
            ans = "RICHARD"
        elif X >= 2*min(C, R):
            ans = "RICHARD"
        elif X <= 2:
            ans = "GABRIEL"
        elif X >= 7:
            ans = "RICHARD"
        else:
            ans = "GABRIEL"

        print("Case #", case+1, ": ", ans, sep="")