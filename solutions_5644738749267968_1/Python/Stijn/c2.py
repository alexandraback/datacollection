f = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/c/in2.in')
T = int(f.readline().strip())
lines = []
for i in range(T*3): lines.append(f.readline().strip().split(' '))

import copy

fo = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/c/out2.out','wb');

for i in range(T):
    naomi = lines[i*3+1];
    ken = lines[i*3+2];
    
    #normal
    naomiwon = 0;
    naomiwon2 = 0;
    naomi2 = copy.deepcopy(naomi)
    ken2 = copy.deepcopy(ken)
    
    
    for j in range(len(naomi2)):
        naomichoose = min(naomi2)
        naomi2.remove(naomichoose);
        listtochoose = [f for f in ken2 if f > naomichoose];
        if(len(listtochoose)>0): 
            kenchoose = min([f for f in ken2 if f > naomichoose]);
        else: 
            kenchoose = min([f for f in ken2 if f < naomichoose]);        
        ken2.remove(kenchoose);
        if(naomichoose>kenchoose): 
            naomiwon +=1;
            
        kenchoose2 = max(ken);
        ken.remove(kenchoose2);
        listtochoose2 = [f for f in naomi if f > kenchoose2];
        if(len(listtochoose2)>0): 
            naomichoose2 = min([f for f in naomi if f > kenchoose2]);
            naomiwon2 += 1;
        else: 
            naomichoose2 = min([f for f in naomi if f < kenchoose2]);
        naomi.remove(naomichoose2);
            

    fo.write("Case #%d: %d %d\n" % (i+1,naomiwon2,naomiwon))

fo.close()