for t in range(1, int(input())+1):
    b, m = map(int,raw_input().split())
    
    if 2**(b-2) < m:
        print "Case #%d: IMPOSSIBLE" % t
        continue
        
    side = len(bin(m))-1
    mat = ['0'*(i+1)+'1'*(side-i-1) for i in range(side)]
    
    maxbit = 2**(side-2)
    m -= maxbit

    if m > 0:
        for i in range(side):
            if i == side-1 or i == 0:
                mat[i] += '1'
            else:
                mat[i] += '0'
        mat += ['0'*(side+1)]
        m -= 1
        
        side += 1
        i = side-2
        while m:
            if m & (1 << i-1):
                mat[i] = mat[i][:-1]+'1'
                m -= 1 << i-1
            i -= 1
    
    for i in range(side):
        mat[i] += '0'*(b-side)
    mat += ['0'*b]*(b-side)
    
    if side != b:
        mat[side-1] = mat[side-1][:-1] + '1'
    
    print "Case #%d: POSSIBLE" % t
    print '\n'.join(mat)