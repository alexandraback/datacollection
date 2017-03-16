

field = {}
changes = []


def find_place(x, y):

    while (x,y) in field:
        y+=2
    
    if y == 0:
        return [(x, y)]
    
    if (x-1,y-1) in field:
        if (x+1,y-1) in field:
            return [(x, y)]
        else:
            return find_place(x+1,y-1)
    
    elif (x+1,y-1) in field:
        return find_place(x-1,y-1)
    
    else:
        a, b = find_place(x-1,y-1), find_place(x+1,y-1)
        if len(a) != 1 or len(b) != 1:
            raise RuntimeError("wrong")
        return [a[0], b[0]]


def undo(place):
    while True:
        p = changes.pop()
        del field[p]
        
        if p == place:
            return


def play(n, place):
    while n > 0:
        places = find_place(0,0)
        if len(places) != 1:
            break
            
        if places[0] == place:
            return 1.0
        
        field[places[0]] = 1.0
        changes.append(places[0])
        
        n-=1
    if n == 0:
        return 0.0
        
    #left
    if places[0] == place:
        p1 = 1.0
    else:
        field[places[0]] = 0.5
        changes.append(places[0])
        p1 = play(n-1, place)
        undo(places[0])

    #right
    if places[1] == place:
        p2 = 1.0
    else:
        field[places[1]] = 0.5
        changes.append(places[1])
        p2 = play(n-1, place)
        undo(places[1])
    
    return 0.5*p1+0.5*p2

    

T = int(input())

for t in range(T):
    
    N, X, Y = list(map(int, input().split()))
    
    field = {}
    changes = []
    print("Case #%d: %0.8f" % (t+1, play(N, (X,Y))))
    
    

