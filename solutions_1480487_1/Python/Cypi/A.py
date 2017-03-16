#! /usr/bin/python
# -*-coding:Utf-8 -*

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

T = readint()
for t in range(T):
    print 'Case #'+str(t+1)+':',
    
    input = readarray(int)
    N = input[0]
    pts = input[1:]
    total = sum(pts)

    P = []
    for i in range(N):
        P.append((pts[i], i))
    P.sort(key=lambda (x,i):-x)
    
    R = []
    
    S = total
    todo = 100.
    
    for i in range(N):
        left = todo*total/100. - ((N-i)*P[i][0] - S)
        if left <= 0:
            R.append((0, P[i][1]))
        else:
            R.append((100.*left/(N-i)/total, P[i][1]))
            todo -= R[-1][0]
        S -= P[i][0]
    
    R.sort(key=lambda (x,y):y)
    for (r,i) in R:
        print r,
    print
