

def solve(n, stages):
    l1_clear = [False] * n
    l2_clear = [False] * n
    
    star_count = 0
    l2_clear_count = 0
    
    for round in range(1, n * 2 + 1):
        select_i1 = -1; max_c1 = -1; max_c1c2 = -1;
        select_i2 = -1; max_c2 = -1; max_c2c1 = -1;
        
        for i in range(len(stages)):
            stage = stages[i]
            
            if not l1_clear[i] and star_count >= stage[0]:
                if stage[0] > max_c1 or (stage[0] == max_c1 and stage[1] > max_c1c2):
                    select_i1 = i
                    max_c1, max_c1c2 = stage[0], stage[1]
                    
            if not l2_clear[i] and star_count >= stage[1]:
                if stage[1] > max_c2 or (stage[1] == max_c2 and stage[0] > max_c2c1):
                    select_i2 = i
                    max_c2, max_c2c1 = stage[1], stage[0]
                    
        # print 'round',round,'select2', select_i2, 'select1', select_i1
        
        if select_i1 == -1 and select_i2 == -1:
            return "Too Bad"
        elif select_i2 != -1:
            if l1_clear[select_i2]:
                star_count -= 1
                
            star_count += 2
            l2_clear[select_i2] = l1_clear[select_i2] = True
            
            l2_clear_count += 1
            
        else:
            l1_clear[select_i1] = True
            star_count += 1
        
        if l2_clear_count == n:
            return round
    
    return "Too Bad"
            
  

if __name__ == '__main__':
    
    fi = open('B-small-attempt0.in','r')
    fo = open('kingdom.out','w')
    
    c = int(fi.readline())
    
    for k in range(1,c+1):
        n = int(fi.readline())
        
        stages = [];
        for i in range(n):
            cost1, cost2 = [int(x) for x in fi.readline().split()]
            stages.append((cost1,cost2))
        
        ans = solve(n, stages)

        fo.write('Case #%d: %s\n' % (k, ans))
        print ans
        print 'done',k,'from',c
    
    fi.close()
    fo.close()