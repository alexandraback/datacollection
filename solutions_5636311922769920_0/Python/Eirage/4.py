file = open('D-small-attempt0.in', 'r')
out = open('result.out','w')
T = int(file.readline())

for Q in range (T):
    out.write('Case #' + str(Q+1) + ': ')
    s = file.readline()
    s = s.split(' ')
    k = int(s[0])
    c = int(s[1])
    s = int(s[2])
    if s * c < k:
        out.write('IMPOSSIBLE\n')
    elif k == 1:
        out.write('1\n')
    else:
        x = 0
        for i in xrange(k):
            x = x * k + i
            if (i+1) % c == 0:
                x += 1
                out.write(str(x)+' ')
                x = 0
        if x != 0:
            x += 1
            out.write(str(x)+' ')
        out.write('\n')
                
        



    
out.close()




