file = open('C-small-1-attempt0.in', 'r')
out = open('result.out','w')

T = int(file.readline())
for k in range (T):
    
    out.write('Case #' + str(k+1) + ': ' + '\n')
    
    s = file.readline()
    s = s.split(' ')
    N = 16#int(s[0])
    J = 50#int(s[1])

    s = '1' * (N-2)
    n = int(s,2)
    for i in range(n):
        x = i
        a = 0
        b = 0
        while x > 0:
            
            if x % 2 != 0:
                a += 1
            x = x // 2
            if x % 2 != 0:
                b += 1
            x = x // 2
        if (a == 4) and (b == 4):
            s = bin(i)
            s = s[2:]
            out.write('1'+s.zfill(14)+'1 ')
            out.write('3 2 5 2 5 2 3 2 11\n')
            J -= 1
            if J == 0:
                break;
out.close()
    
            
        
        
            
                


            

    

    


