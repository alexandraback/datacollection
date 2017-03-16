from numpy import array, fromfile, floor, zeros



def main(inp):
    
    arr = fromfile(inp, sep=' ', dtype=int)
    
    R = arr[5:].reshape((arr[1], arr[4]))
    print "Case #1:"
    for i, K in enumerate(R): 
        print '2'*arr[2]
    return    
    
    r = range(2, arr[3]+1)
    l = [(a,b,c,d,e,f,g,h,i,j,k,l) for a in r for b in r for c in r for d in r for e in r for f in r for g in r for h in r for i in r for j in r for k in r for l in r]
    print len(l[0])
    return
    a = array(l)
    p = a.prod(1)

    print "Case #1:"
    for i, K in enumerate(R): 
        z = zeros(len(p))
        for x in K:
            z[p==x] += 1
        s = a[z>0]
        for v in s[::-1]:
            if not 1 in v:
                print ''.join([str(o) for o in v])
                break
        else:
            print '2' * arr[2]
    
    
    
    
if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        print('Usage: a.py input output')
    else:
        main(sys.argv[1])
