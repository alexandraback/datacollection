from numpy import array, fromfile, floor, float128



def main(inp):
    
    rt = fromfile(inp, sep=' ', dtype=float128)
     
    rt = rt[1:].reshape((rt[0], 2))

    r = rt[:,0]
    t = rt[:,1]
    b = (r + 1)**2 - r**2 - 2
    c = -t
    a = 2
    d = (b**2 - 8*c)**0.5
    n = floor(((-b+d)/4))
    for i, x in enumerate(n): 
        print('Case #{0}: {1:.0f}'.format(i+1, x))
    
    
    
    
if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        print('Usage: a.py input output')
    else:
        main(sys.argv[1])
