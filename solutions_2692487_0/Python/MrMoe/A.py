

T = int(input())


def play(i, a, motes):
    while i < len(motes) and a > motes[i]:
        a += motes[i]
        i += 1
    if i == len(motes):
        return 0
        
    #add
    if a > 1:
        m1 = play(i, a+a-1, motes)+1
    else:
        m1 = 999999999999999

    #remove
    m2 = play(i+1, a, motes)+1
    
    if m1 < m2:
        return m1
    else:
        return m2
            
            

for t in range(T):
    
    A, N = list(map(int, input().split()))
    motes = sorted(list(map(int, input().split())))
    if len(motes) != N:
        raise RuntimeError("incorrect number")
    
    print("Case #%d: %d" % (t+1, play(0, A, motes)))
        
    

