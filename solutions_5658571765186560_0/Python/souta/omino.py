import math

fin = open('D-small-attempt1.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    [x, r, c] = [int(i) for i in fin.readline().split()]
    result = 'RICHARD';
    if x >= 7:
        result = 'RICHARD'
    elif r * c % x != 0:
        result = 'RICHARD'
    elif x == 3 and (r <= 1 or c <= 1):
        result = 'RICHARD'
    elif x == 4 and (r <= 2 or c <= 2):
        result = 'RICHARD'
    elif x == 5 and (r <= 2 or c <= 2):
        result = 'RICHARD'
    elif x == 5 and r == 3 and c == 5:
        result = 'RICHARD'
    elif x == 5 and r == 5 and c == 3:
        result = 'RICHARD'
    elif x == 6 and (r <= 3 or c <= 3):
        result = 'RICHARD'
    else:
        result = 'GABRIEL'
    
    fout.write('Case #'+str(count)+': '+ result +'\n')
fin.close()
fout.close()
