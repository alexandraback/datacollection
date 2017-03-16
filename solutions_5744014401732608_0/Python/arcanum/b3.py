from math import *

def rl(l): return range(len(l))



f = open("prog.out", mode='w')

T = int(input())

def leftpad(s, n):
    return '0'*(n-len(s))+s

def rightpad(s,n):
    return s+ '0'*(n-len(s))

B = 0
M = 0

def do (l, indsl):
    #print(len(l))
    if len(l) == B: # reached end
        if l[-1] == M:
            return indsl
        else:
            return None
        
    for i in range(2**len(l)):
        inds = list(int(e) for e in leftpad(bin(i)[2:], len(l)))

        l_ =l[::-1]
        thesum = sum(inds[i]*l_[i] for i in range(len(l_)))
        newl = [e for e in l]
        newl.append(thesum)

        inds = [0]*(B-len(inds))+inds
        
        newindsl = [e for e in indsl]
        newindsl.append(inds)
        
        an = do(newl, newindsl)
        if an:
            return an
    return None

'''
4
3 2
4 2
5 4
2 1
4 20
4 2
'''

for nt in range(1, T+1):
    B,M = list(map(int, input().split()))
    an = do([1],[[0 for i in range(B)]])

    ans = "IMPOSSIBLE"
    il = an
    if il:
        ans = "POSSIBLE\n"
    
        ans += "\n".join("".join(str(e) for e in q) for q in an[::-1])

    
    #print(ans)
    
    towrite = "Case #"+str(nt)+": "+str(ans)+'\n'
    f.write(towrite)
    print(towrite, end="")
    
f.close()

