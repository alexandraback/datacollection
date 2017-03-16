ri = lambda : raw_input().strip()
rim = lambda tp, deli: map(tp, ri().split(deli))

def print_result(data):
    for _i in data:
        print ''.join(_i)


n = int(ri())

for i in xrange(0, n):
    print 'Case #{0}:'.format(i+1)

    r, c, m = rim(int, ' ')
    mmap = [['*' for _c in xrange(c)] for _r in xrange(r)]
    
    if r*c-1 == m:
        mmap[r-1][c-1] = 'c'
        print_result(mmap)
    
    elif r == 1 and c == 1:
        print 'c'
        
    elif r == 1 or c == 1:
        if m <= r*c-2:
            tmp = 0
            
            for _x in xrange(r):
                for _y in xrange(c):
                    if tmp < m:
                        mmap[_x][_y] = '*'
                        tmp += 1
                    else:
                        mmap[_x][_y] = '.'
                
            mmap[_x][_y] = 'c'
            print_result(mmap)
        else:
            print 'Impossible'
    
    elif r == 2 or c == 2:
        if m <= r*c-4:
            if m %2 == 0:
                if r == 2:
                    mmap[0] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                    mmap[1] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                    
                else:
                    for _x in range(r):
                        if m > 0:
                            mmap[_x] = ['*' for _ in xrange(c)]
                            m -= 2
                        else:
                            mmap[_x] = ['.' for _ in xrange(c)]
                    
                mmap[r-1][c-1] = 'c'
                print_result(mmap)
                
            else:
                print 'Impossible'
                
        else:
            print 'Impossible'
    
    else:
        if m == r*c-4:
            mmap[r-1][c-1] = 'c'
            mmap[r-1][c-2] = '.'
            mmap[r-2][c-1] = '.'
            mmap[r-2][c-2] = '.'
            print_result(mmap)
            
        elif m < r*c-4:
            _y = 0
            is_done = False
            is_impossible = False
            
            for _x in xrange(r):
                if is_done:
                    continue
                
                sa = r - _x
                sd = m % sa
                sf = m / sa
                
                if m >= c:
                    if sa == 2:
                        if m % 2 == 0:
                            mmap[_x] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                            mmap[_x+1] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                            is_done = True
                            
                        else:
                            is_done = True
                            is_impossible = True
                        
                    else:
                        if sd == 0:
                            if sf == c-1:
                                is_done = True
                                is_impossible = True
                            else:
                                for _v in xrange(_x, r):
                                    mmap[_v] = ['*' for _ in xrange(m/sa)] + ['.' for _ in xrange(c - m/sa)]
                                
                                is_done = True
                            
                        else:
                            mmap[_x] = ['*' for _ in xrange(c)]
                            m -= c
                        
                else:
                    if sa > 2:
                        if sd == 0:
                            for _v in xrange(_x, r):
                                mmap[_v] = ['*' for _ in xrange(m/sa)] + ['.' for _ in xrange(c - m/sa)]
                            
                            is_done = True

                        else:
                            p = m / sa
                            for _p in xrange(_x, r):
                                mmap[_p] = ['*']*p + ['.']*(c-p)
                            
                            for _p in xrange(sd):
                                if c - p - _p == 2:
                                    if r - _x - 1 == 2:
                                        is_done = True
                                        is_impossible = True
                                        break
                                        
                                    else:
                                        mmap[_x+1][p] = '*'
                                else:
                                    mmap[_x][p+_p] = '*'
                            
                            m = 0
                            is_done = True
                    
                    else: # sa <= 2
                        if m % 2 == 0:
                            if sa == 2:
                                mmap[_x] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                                mmap[_x+1] = ['*' for _ in xrange(m/2)] + ['.' for _ in xrange(c - m/2)]
                                is_done = True
                                
                            else:
                                pass
                                
                        else:
                            is_impossible = True
                            is_done = True
                        
            mmap[r-1][c-1] = 'c'
            
            if is_impossible:
                print 'Impossible'
                
            else:
                print_result(mmap)
                
        else:
            print 'Impossible'
            
            
            
    
