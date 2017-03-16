fin = open('B.in', 'r')
fout = open('file.out', 'w')
n = fin.readline()
    
for l in range(int(n)):
    b,m = map(int,fin.readline().split())
    if m > 2 ** (b-2):
        fout.write('Case #%d: IMPOSSIBLE\n'%(l+1))
    else:
        fout.write('Case #%d: POSSIBLE\n'%(l+1))
        fout.write('0')
        for i in range(b-1):
            if 2 ** (max(b-i-3,0)) <= m:
                fout.write('1')
                m -= 2 ** (max(b-i-3,0))
            else:
                fout.write('0')
        fout.write('\n')
        for i in range(b-1):
            fout.write(''.join(['0' for i in range(i+2)] + ['1' for i in range(b-i-1)])+'\n')
    

    
    """fout.write("Case #%d: "%(l+1))
    fout.write(' '.join(map(lambda x: ''.join(map(lambda y:chr(65 + y),x)),output)) + '\n')"""
        
    
fin.close()
fout.close()
