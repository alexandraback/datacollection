import math
T = int(raw_input())

consonants = "bcdfghjklmnpqrstvwxyz"

def gen_sub(s):
    L = len(s)
    for start in range(0, L+1):
        for end in range(start, L+1):
            yield s[start:end]

def check(s, n):
    L = len(s)
    i = 0
    num_conse_cons = 0
    while i < L:
        if s[i] not in consonants:
            num_conse_cons = 0
        else:
            num_conse_cons += 1
            if num_conse_cons >= n:
                return True
        i += 1
    
    return False
             
            
for t in range(T):
    line = [i.strip() for i in raw_input().split()]
    name = line[0]
    n = int(line[1])
    
    res = 0
    iter = gen_sub(name)
    #print name
    try:
        while True:
            s = iter.next()
            if check(s, n):
                res += 1
            
            #print s, n, res
            
    except StopIteration:
        pass
            
    print 'Case #%s: %s' % (t+1, res)