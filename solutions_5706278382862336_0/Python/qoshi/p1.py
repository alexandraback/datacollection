
def solve(x,y,z):
    if ( z > 40 ):
        return -1
    if ( x == y or x == 0 ):
        return z
    if ( x > y ):
        if ( solve(x-y,y,z) != -1 ):
            return z
        else:
            return -1
    if ( y%2 == 0 ):
        y /= 2
    else:
        x *= 2
    return solve(x,y,z+1)

n = int(input())
for i in range(1,n+1):
    x,y = input().split("/")
    x = int(x)
    y = int(y)
    z = solve(x,y,0)
    if ( z != -1 ):
        print("Case #%d: %d"%(i,z))
    else:
        print("Case #%d: impossible"%i)
