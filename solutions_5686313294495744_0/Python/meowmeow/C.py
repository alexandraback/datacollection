from itertools import product as product

        
    

F = open('C-small-attempt0.in')
O = open('C-small-attempt0.out','w')

#F = open('C-large-practice.in')
#O = open('C-large-practice.out','w')


T = int(F.readline().rstrip())

print T


for case in range(1,T+1):
    N = int(F.readline().rstrip())

    print N
    store = []

    ans = 0
    
    for _ in range(N):
        store.append(F.readline().rstrip().split())


    for x in product('01',repeat = N): # 0 = fake 1 = real, max fake!
        fakes = sum(1 for t in x if t == '0')
        first = set()
        second = set()
        for i in range(N):
            if x[i] == '1':
                first.update([store[i][0]])
                second.update([store[i][1]])


        for i in range(N):
            if x[i] == '0':
                if store[i][0] not in first or store[i][1] not in second:
                    break

        else:
            ans = max(ans,fakes)
                
            

        
                
            

    O.write('Case #%d: %d\n'%(case,ans))
        
        
                
                
        



F.close()
O.close()
    
        
