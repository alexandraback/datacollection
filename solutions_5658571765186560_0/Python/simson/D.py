import sys

def get_line():
    return sys.stdin.readline()

def get_ints():
    return [int(i) for i in get_line().split()]
    
for e,n in enumerate(range(get_ints()[0])):
    x, r, c = get_ints()

    if r > c:
        r, c = c, r
        
    res = True
    
    if (r * c) % x != 0:
        res = False
    else:
        res = x == 1 or x==2 or x==3 and r>=2 or x==4 and r>=3 \
        or x==5 and r==3 and c>=10 \
        or x==5 and r>=4 \
        or x==6 and r>=4 
        
    print("Case #%i: %s" % (e+1, "GABRIEL" if res else "RICHARD"))
                