F = open('D-small-attempt0.in')
O = open('D-small-attempt0.out','w')

#F = open('B-large.in')
#O = open('B-large.out','w')


T = int(F.readline())

print T

for case in range(1,T+1):
    K,C,S = map(int,F.readline().rstrip().split())

    ans = ' '.join(str(i) for i in range(1,K+1)) + '\n'

    
    O.write('Case #%d: %s'%(case,ans))
    


F.close()
O.close()
    
        
