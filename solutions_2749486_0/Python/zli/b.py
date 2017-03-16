from point import Point as P

def vadd(u,v):
    return (u[0]+v[0],u[1]+v[1])

def vmult(c,v):
    return (c*v[0],c*v[1])

solution = {(0,0):""}
xys = [(0,0)]
index = 0
dirs = {"N":(0,1),"S":(0,-1),"E":(1,0),"W":(-1,0)}
maxlen = 0
while xys:
    xy = xys[index]
    sol = solution[xy]
    if len(sol)>maxlen:
        maxlen = len(sol)
        print maxlen, index, len(solution)
    if len(sol) == 101:
        break
    for c,dir in dirs.items():
        newxy = vadd(xy, vmult(len(sol)+1, dir))
        if newxy not in solution:
            solution[newxy] = sol+c
            xys.append(newxy)
    index += 1

for case in range(input()):
    print "Case #"+str(case+1)+":",
    x,y=map(int,raw_input().split())
    s=raw_input().split()    
    li=[[0 for i in xrange(10)] for j in xrange(10)]
