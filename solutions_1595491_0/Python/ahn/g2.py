'''
Created on 14.4.2012

@author: Antti
'''

def p_without_surprise(total, p):
    return total >= 3*p - 2

def p_w_surprise(total, p):
    if total==0:
        return p<=0
    elif total==1:
        return p<=1
    else:
        return total >= 3*p - 4

def over_w_surprise(under, s, p):
    under.sort(reverse=True)
    surp = 0
    for x in under:
        if s<=0:
            break
        if p_w_surprise(x, p):
            surp += 1
            s -= 1
    return surp

def calc(points, s, p):
    num_over = 0
    under = []
    for x in points:
        if p_without_surprise(x, p):
            num_over += 1
        else:
            under.append(x)
    return num_over + over_w_surprise(under, s, p)

def solve(filename):
    
    with file(filename) as f:
        cases = int(f.readline().strip())
        
        for i in range(cases):
            ints = [int(p) for p in f.readline().split()]
            S = ints[1]
            p = ints[2]
            points = ints [3:]
            print 'Case #%i: %s' % (i+1, calc(points,S,p))
            
            
if __name__ == '__main__':
    solve('B-small-attempt3.in')