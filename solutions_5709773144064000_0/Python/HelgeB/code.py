'''
Created on 15.03.2014

@author: Helge
'''

file = open('B-small-attempt0.in', 'r')
output = open('output', 'w')

numberOfTestcases = file.readline()

for i in range(0, int(numberOfTestcases)):
    line = file.readline().replace('\n', '').split(' ')
    C = float(line[0])
    F = float(line[1])
    X = float(line[2])
    
    repeat = 1
    cookiesPerSecond = 2
    usedTime = 0
    while repeat == 1:
        timeWithoutNewFarm = X/cookiesPerSecond
        timeWithNewFarm = C/cookiesPerSecond + X/(cookiesPerSecond+F)
    
        if timeWithNewFarm >= timeWithoutNewFarm:
            repeat = 0
            usedTime = usedTime + timeWithoutNewFarm
        else:
            usedTime = usedTime + C/cookiesPerSecond
            cookiesPerSecond = cookiesPerSecond + F
        
        
        
    
    
    solution = 'Case #' + str(i+1) + ': ' + str(usedTime)
        
    print(solution)
    output.write(solution + '\n')  
    
