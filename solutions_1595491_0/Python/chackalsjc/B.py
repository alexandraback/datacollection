# Google Code Jam 2012 Qualification Round
# B

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        line = raw_input().split()
        N = int(line[0])
        S = int(line[1])
        p = int(line[2])
        t = []
        for j in line[3:]:
            t.append(int(j))
        y = 0
        for j in t:
            d = j / 3
            m = j % 3
            # triplet is (d, d, m)
            if p == 0:
                y += 1
                continue
            if j == 0:
                continue
            
            if d >= p:
                # print j
                y += 1
            elif m == 0 and S > 0 and d + 1 >= p:
                # print j
                y += 1
                S -= 1
            elif m == 1 and d + m >= p:
                # print j
                y += 1
            elif m == 2:
                if d + 1 >= p:
                    # print j
                    y += 1                    
                elif S > 0 and d + m >= p:
                    # print j
                    y += 1
                    S -= 1
        
        print 'Case #%d: %d' % (i+1, y)