##f =open('test.txt','r')
##fout = open('test_result.txt','w')

f =open('D-small-attempt1.in','r')
fout = open('small_result.txt','w')

casenum = int(f.readline().split('\n')[0])
for case in range(casenum):
    [x,r,c] = f.readline().split('\n')[0].split(' ')
    x = int(x)
    r = int(r)
    c = int(c)
    wr = 'RICHARD'
    wg = 'GABRIEL'
    
    # go through all small test case for x
    if x == 1:
        winner = wg
    elif x == 2:
        if r%2 == 1 and c%2 ==1:
            winner = wr
        else:
            winner = wg
    elif x == 3:
        if ((r*c)%3 == 0) and r >=2 and c>=2:
            winner = wg
        else:
            winner = wr
    else:
        if (r==4 and c >= 3) or (c == 4 and r >=3):
            winner = wg
        else:
            winner = wr
    fout.write('Case #'+str(case+1)+': '+winner)
    fout.write('\n')
       
f.close()        
fout.close()
