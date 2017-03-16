import sys;
inFile = open("C-small-attempt0.in","r");
sys.stdin = inFile;
outFile = open("C-small-out.out","w");
sys.stdout = outFile;

caseCount = eval(input());

for caseIndex in range(0, caseCount):
    tribeCount = eval(input());
    
    wallHeights = {};
    goodAttacks = 0;
    attacksRemaining = 0;
    
    attackStartT = [0]*tribeCount;
    attackCount = [0]*tribeCount;
    westMostAttack = [0]*tribeCount;
    eastMostAttack = [0]*tribeCount;
    attackStrength = [0]*tribeCount;
    attackTInterval = [0]*tribeCount;
    attackDInterval = [0]*tribeCount;
    attackSInterval = [0]*tribeCount;
    
    for i in range(0, tribeCount):
        data = input().split(" ");
        
        attackStartT[i] = eval(data[0]);
        attackCount[i] = eval(data[1]);
        westMostAttack[i] = eval(data[2]);
        eastMostAttack[i] = eval(data[3]);
        attackStrength[i] = eval(data[4]);
        
        attackTInterval[i] = eval(data[5]);
        attackDInterval[i] = eval(data[6]);
        attackSInterval[i] = eval(data[7]);
        
        attacksRemaining += attackCount[i];
        
    time = 0;
    while(attacksRemaining > 0):
        wallHInc = [];
        
        for tribe in range(0, tribeCount):
            #print("Day "+str(time)+" - "+str(attacksRemaining)+" attacks left");
            
            if(attackCount[tribe] > 0 and  time >= attackStartT[tribe] and (time-attackStartT[tribe])%attackTInterval[tribe] == 0):
                #ATTACK!
                success = False;
                #print("Attack from "+str(tribe)+" at height "+str(attackStrength[tribe]));
                
                for i in range(westMostAttack[tribe], eastMostAttack[tribe]):
                    
                    if(not (i in wallHeights)):
                        wallHeights[i] = 0;
                        
                    if(wallHeights[i] < attackStrength[tribe]):
                        wallHInc.append((i,attackStrength[tribe]));
                        success = True;
                
                if(success):
                    #print("Attack succeeded");
                    goodAttacks += 1;    
                #else:
                   # print("Attack failed");
                    
                westMostAttack[tribe] += attackDInterval[tribe];
                eastMostAttack[tribe] += attackDInterval[tribe];
                attackStrength[tribe] += attackSInterval[tribe];
                attackCount[tribe] -= 1;
                attacksRemaining -= 1;
        
        #Increase wall heights   
        for i in range(0, len(wallHInc)):
            wallHeights[wallHInc[i][0]] = max(wallHeights[wallHInc[i][0]],wallHInc[i][1]);
            
        #print(wallHeights);
        time += 1;
                
    
    
    print("Case #"+str(caseIndex+1)+": "+str(goodAttacks));