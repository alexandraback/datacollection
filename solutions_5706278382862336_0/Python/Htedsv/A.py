def fra(x, y):
    if x % y == 0:
        return y
    return fra(y, x % y)

def p2(x):
    if x == 1:
        return True
    if x % 2 != 0:
        return False
    return p2(x/2)
def ra(a, b):
    if a * 2 >= b: 
        return 1
    else:
        return 1 + ra(a*2, b)
f = open("data.in")
T = int(f.readline())
for I in range(1, T+1):
    p = f.readline()
    sep = p.find('/')
    a = int(p[:sep])
    b = int(p[sep+1:])
    p = fra(a, b)
    a, b = a/p, b/p
    if not p2(b):
        print "Case #%d: impossible"%I
    else:
        print "Case #%d: %d"%(I,ra(a, b))



