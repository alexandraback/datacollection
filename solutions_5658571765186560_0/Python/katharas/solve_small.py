
def solve(X, R, C):
    if X >= 7:
        return "RICHARD"

    if X > R and X > C:
        return "RICHARD"

    if X == 1:
        return "GABRIEL"

    if X == 2: 
        if R%2 == 1 and C%2==1:
            return "RICHARD"
        else:
            return "GABRIEL"

    if X == 3:
        boards = {}
        boards[(3, 1)] = True
        boards[(3, 2)] = False
        boards[(3, 3)] = False
        boards[(4, 1)] = True
        boards[(4, 2)] = True
        boards[(4, 3)] = False
        boards[(4, 4)] = True
        return "RICHARD" if boards[(max(R,C), min(R,C))] else "GABRIEL"

    if X == 4:
        boards = {}
        boards[(4, 1)] = True
        boards[(4, 2)] = True
        boards[(4, 3)] = True
        boards[(4, 4)] = False
        return "RICHARD" if boards[(max(R,C), min(R,C))] else "GABRIEL"


T = int(raw_input())
for t in range(1, T+1):
    print "Case #%d: %s" % (
        t,
        solve(*map(int, raw_input().split()))
    )
