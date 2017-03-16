import sys

def solve(box,toy):
    if (box==[]) or (toy==[]):
        return 0
    elif box[0][1] == toy[0][1]:
        if box[0][0] == toy[0][0]:
            return box[0][0] + solve(box[1:],toy[1:])
        elif box[0][0] > toy[0][0]:
            box[0] = (box[0][0]-toy[0][0],toy[0][1])
            return toy[0][0] + solve(box,toy[1:])
        else:
            toy[0] = (toy[0][0]-box[0][0],toy[0][1])
            return box[0][0] + solve(box[1:],toy)
        
    else:
        return max(solve(box,toy[1:]),solve(box[1:],toy))

T = int(sys.stdin.readline())
for i in range(T):
    n,m = map(int,sys.stdin.readline().split())
    line = map(int,sys.stdin.readline().split())
    box = []
    for j in range(n):
        box.append((line[2*j],line[2*j+1]))
    line = map(int,sys.stdin.readline().split())
    toy = []
    for j in range(m):
        toy.append((line[2*j],line[2*j+1]))
    print "Case #%d: %d"%(i+1,solve(box,toy))
    
