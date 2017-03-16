import scipy as sp

def mycmp(x,y):
    return -cmp(x[1],y[1])

T = int(raw_input(''))
for t in range(T):
    N = int(raw_input(''))
    levels = []
    for i in xrange(N):
        line = raw_input('')
        levels.append(map(int, line.split(' ')))
    

#    debuglevels = [e[:] for e in levels]

    steps = 0
    stars = 0
        
    while levels:
        lf = filter(lambda l: l[1] <= stars, levels)
        if lf:
            steps += 1
            l = lf[0]
            levels.remove(l)
            if l[0] >= 0:
                stars += 2
            else:
                stars += 1
        else:
            lf = filter(lambda l: 0 <= l[0] <= stars, levels)
            if lf:
                lf.sort(cmp=mycmp)
                steps += 1
                l = lf[0]
                l[0] = -1
                stars += 1
            else:
                # No possible choice:
                steps = "Too Bad"
                answer = "Too Bad"
                break;
            

    print ("Case #%d:"%(t+1)), steps#, debuglevels
