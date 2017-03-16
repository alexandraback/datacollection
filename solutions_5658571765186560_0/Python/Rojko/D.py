p1 = ((1,0,0,0),(1,1,0,0),(1,0,0,0),(1,1,0,0))
p2 = ((1,1,0,0),(1,1,0,0),(1,1,1,0),(1,1,0,0))
p3 = ((1,0,0,0),(1,1,1,0),(1,0,1,0),(1,1,1,1))
p4 = ((1,1,0,0),(1,1,0,0),(1,1,1,1),(1,1,0,1))
p = (p1,p2,p3,p4)
T = int(input())
for t in range(1,T+1):
    x,r,c = map(int,input().split())
    r,c,x = r-1, c-1, x-1
    print("Case #%d: %s" % (t, "GABRIEL" if p[r][c][x] == 1 else "RICHARD"))
    #print("%d , %d (%d): %s" % (r+1, c+1, x+1, "GABRIEL" if p[r][c][x] == 1 else "RICHARD"))
