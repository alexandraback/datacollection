
INF = float('inf') 

T = input() 

def gcd(a, b): 
    if b == 0: 
        return a 
    return gcd(b, a%b)

def update(p, q): 
    d = gcd(p, q) 
    return (p/d, q/d) 

def valid(p, q): 
    p, q = update(p, q) 
    if p%2 == 0: 
        return False 

    while True: 
        if q == 1: 
            return True 
        if q % 2 != 0: 
            return False 
        q /= 2 

def get_generation(p, q): 
    p, q = update(p, q) 
    if p == 0: 
        return INF 
    if q == 1: 
        return 0

    if p >= q/2: 
        return 1 

    return get_generation(p, q/2) + 1 
    
for t in range(1, T+1): 
    p, q = map(int, raw_input().split('/')) 

    if valid(p, q): 
        print 'Case #%d: %s' %(t, get_generation(p, q))
    else: 
        print 'Case #%d: impossible' %(t) 

