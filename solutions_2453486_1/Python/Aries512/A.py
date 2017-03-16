def scored(s,c):
    x1 = [i.strip().replace('T',c) for i in s]
    x2 = [''.join([x1[i][j] for i in range(4)]) for j in range(4)]
    d1 = ''.join([x1[i][i] for i in range(4)])
    d2 = ''.join([x1[3-i][i] for i in range(4)])
    return True if 4*c in x1+x2+[d1]+[d2] else False

f = open('D:/AAA/google_jam/A-large.in','r')
fout = open('D:/AAA/google_jam/A.out','w')
T = int(f.readline())
for t in range(1,T+1):
    s = [f.readline(),f.readline(),f.readline(),f.readline()]
    f.readline()
    fout.write('Case #'+str(t)+': ')
    if scored(s,'X'): fout.write('X won\n')
    elif scored(s,'O'): fout.write('O won\n')
    elif '.' not in ''.join(s): fout.write('Draw\n')
    else: fout.write('Game has not completed\n')
f.close()
fout.close()

