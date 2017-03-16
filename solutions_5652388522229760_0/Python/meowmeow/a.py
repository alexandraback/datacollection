F = open('A-small-attempt0.in')
O = open('A-small-attempt0.out','w')

#F = open('A-large-practice.in')
#O = open('A-large-practice.out','w')


T = int(F.readline())

print T

for case in range(1,T+1):
    N = int(F.readline())
    if N == 0:
        O.write('Case #%d: INSOMNIA\n'%(case))


    else:
        seen = set(i for i in str(N))
        x = N
        while True:
            x += N
            seen = seen | set(i for i in str(x))
            if len(seen) == 10:
                ans = x
                break
            


        O.write('Case #%d: %d\n'%(case,ans))
    


F.close()
O.close()
    
        
