def solve():
    S = input().strip()
    poss=[]
    def possibles(cur, rem):
        if(rem == ""):
            poss.append(cur)
        else:
            possibles(cur+rem[0], rem[1:])
            possibles(rem[0]+cur, rem[1:])
    
    possibles(S[0], S[1:])
    poss.sort()
    return poss[-1]

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solve()))
