RICHARD = 'RICHARD'
GABRIEL = 'GABRIEL'

def check(X,R,C):
    if X >= 7:
        return RICHARD
    if (R*C)%X != 0:
        return RICHARD
    if X == 3 and min(R,C) == 1:
        return RICHARD
    if X <= 3:
        return GABRIEL
    if X==4:
        return check4(R,C)
    if X==5:
        return check5(R,C)
    if X==6:
        return check6(R,C)

def check4(R,C):
    if R<=2 or C<=2:
        return RICHARD
    return GABRIEL

def check5(R,C):
    if not (R%5):
        return check5(C,R)
    if C <= 2:
        return RICHARD
    if C ==3 and R == 5:
        return RICHARD
    return GABRIEL

def check6(R,C):
    if min(R,C) <= 3:
        return RICHARD
    return GABRIEL
    

T = int(input())
for case in range(1,T+1):
    X,R,C = (int(x) for x in input().split())
    
    ans = check(X,R,C)
    print("Case #",case,": ",ans,sep = '')
