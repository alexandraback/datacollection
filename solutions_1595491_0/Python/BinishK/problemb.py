def main():
    fi = open('B-small-attempt2.in')
    fo = open('B-small-attempt2.out', 'w')
    t = int(fi.readline())
    
    for i in range(t):
        l = fi.readline().strip()
        tc = [int(t) for t in l.split()]
        
        N = tc[0]
        S = tc[1]
        P = tc[2]
        C = tc[3:]
        
        o = 0
        valid = 0
        possible = 0
        for c in C:
            d,r = divmod(c, 3)
            
            if P == 0:
                valid = valid + 1
                continue
            if c == 0:
                continue
            
            if d >= P:
                valid = valid + 1
            elif r > 0 and (d+1) == P:
                valid = valid + 1
            
            elif r == 2 and (d+2) >= P:
                possible = possible + 1  
            elif (r == 1 or r == 0) and (d+1) >= P:
                possible = possible + 1
        
        
        #print l, C, valid, possible, S
        o = valid + min(possible, S)
        
        fo.write("Case #%d: %d\n" % (i+1, o))
        #fo.write("Case #%d: %d <= %s => %s, %d, %d, %d\n" % (i+1, o, l, C, valid, possible, S))
        print "Case #%d: %d" % (i+1, o)        

if __name__ == "__main__":
    main()