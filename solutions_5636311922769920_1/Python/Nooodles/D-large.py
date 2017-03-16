### Google code jam 2016
### Qualification round
### Fractiles-large

def position(K, c):
    value = 0;
    for index in range(c):
        value = value*K + index;
    return value;
    
Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),
    [K, C, S] = map(int, raw_input().split());

    if (K/C > S):
        print "IMPOSSIBLE";
    else:
            offset = 1;
            todo = K;
            while (todo > 0):
                current = min(todo, C);
                todo -= C;
                print position(K, current) + offset,
                offset += K**(C-1)*C
            print 
            
        
    
