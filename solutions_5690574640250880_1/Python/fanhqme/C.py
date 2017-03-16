T=int(raw_input())
def construct(R,C,M):
    if R==1 or C==1:
        if R==1:
            print '*'*M+(R*C-M-1)*'.'+'c'
        else:
            print '\n'.join('*'*M+(R*C-M-1)*'.'+'c')
        return
    E=R*C-M
    if E==1:
        for i in xrange(R):
            if i==0:
                print 'c'+'*'*(C-1)
            else:
                print '*'*C
        return
    if R==2 or C==2:
        if E==2 or E%2==1:
            print 'Impossible'
            return
        else:
            if R==2:
                print 'c'+'.'*(E/2-1)+'*'*(C-E/2)
                print '.'*(E/2)+'*'*(C-E/2)
            else:
                print 'c.'
                for i in xrange(E/2-1):
                    print '..'
                for i in xrange(R-E/2):
                    print '**'
            return
    else:
        E=R*C-M
        if E in [2,3,5,7]:
            print 'Impossible'
            return
        elif E>=C*2:
            U=[['*' for i in xrange(C)] for j in xrange(R)]
            for i in xrange(E):
                U[i//C][i%C]='.'
            if E%C==1:
                U[E//C][1]='.'
                U[E//C-1][-1]='*'
                if E//C==2:
                    U[E//C][2]='.'
                    U[E//C-2][-1]='*'
            U[0][0]='c'
            print '\n'.join(''.join(i) for i in U)
        else:
            if E%2==0:
                print 'c'+'.'*(E/2-1)+'*'*(C-E/2)
                print '.'*(E/2)+'*'*(C-E/2)
                for i in xrange(R-2):
                    print '*'*C
            else:
                print 'c'+'.'*((E-3)/2-1)+'*'*(C-(E-3)/2)
                print '.'*((E-3)/2)+'*'*(C-(E-3)/2)
                print '...'+'*'*(C-3)
                for i in xrange(R-3):
                    print '*'*C
for case in xrange(1,T+1):
    print 'Case','#%d:'%case
    R,C,M=map(int,raw_input().strip().split())
    construct(R,C,M)
