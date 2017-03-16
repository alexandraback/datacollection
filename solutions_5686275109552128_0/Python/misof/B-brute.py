T = int( input() )
for t in range(1,T+1):
    D = int( input() )
    P = [ int(x) for x in input().split() ]
    P.sort()
    states = set([ tuple(P) ])
    steps = 0
    while True:
        steps += 1
        new_states = set()
        done = False
        for P in states:
            Q = [ x-1 for x in P if x != 1 ]
            if Q == []:
                done = True
                break
            new_states.add( tuple(Q) )
            for i in range(len(P)):
                if P[i] > 1:
                    for j in range(1,(P[i]//2)+1):
                        Q = [ P[k] for k in range(len(P)) if k!=i ] + [ j, P[i]-j ]
                        Q.sort()
                        new_states.add( tuple(Q) )
        if done:
            print('Case #{}: {}'.format(t,steps))
            break
        states = new_states
