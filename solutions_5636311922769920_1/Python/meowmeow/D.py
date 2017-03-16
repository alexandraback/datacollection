#F = open('D-small-attempt0.in')
#O = open('D-small-attempt0.out','w')

F = open('D-large.in')
O = open('D-large.out','w')


T = int(F.readline())

print T

for case in range(1,T+1):
    K,C,S = map(int,F.readline().split())

    if K == S:
        ans = ' '.join(str(i) for i in range(1,K+1)) + '\n'
    elif S == K-1 and C != 1:
        ans = ' '.join(str(i) for i in range(2,K+1)) + '\n'
    else:
        ans = 'IMPOSSIBLE\n'

    
    O.write('Case #%d: %s'%(case,ans))
    


F.close()
O.close()
    
        
