"""
1
3 2 0

"""
def getSuccessor(oldlist):
    maxY = 0  
    for point in oldlist:
        if maxY < point[1] and point[0] == 0:
            maxY = point[1]
    
    X = 0
    Y = maxY + 2
    
    newlist = []
    # Left
    count = 0
    while True:
        if Y == 0 and (X,Y) not in oldlist:
            listc = list(oldlist)
            listc.append((X,Y))
            newlist.append(listc)
            break 
        elif (X-1,Y-1) not in oldlist:
            X = X - 1
            Y = Y - 1
            count += 1
        elif (X-1,Y-1) in oldlist:
            listc = list(oldlist)
            if count!= 0:
                listc.append((X,Y))
                newlist.append(listc)
            break          
    X = 0
    Y = maxY + 2
    count1 = 0
    #Right
    while True:
        if Y == 0 and (X,Y) not in oldlist:
            listc = list(oldlist)
            listc.append((X,Y))
            newlist.append(listc)
            break 
        elif (X+1,Y-1) not in oldlist:
            X = X + 1
            Y = Y - 1
            count1 +=1
        elif (X+1,Y-1) in oldlist:
            listc = list(oldlist)
            if count1!= 0:
                listc.append((X,Y))
                newlist.append(listc)
            break          
    
    X = 0
    Y = maxY + 2
    
    if count ==0 and count1 == 0:
        listc = list(oldlist)
        listc.append((X,Y))
        newlist.append(listc)           
    return newlist
    

def GetAllList(list):
    result = []
    for data in list:
        for re in getSuccessor(data):
            result.append(re)
    return result

def getProb(N,X,Y):
    result = 0.0
    list = [[(0, 0)]]
    for i in range(0,N-1):
        list = GetAllList(list) 
    #for i in list:
    #    print i
    count = 0.0
    tot = len(list)
    for data in list:
        for point in data:
            if point == (X,Y):
                count +=1
    
    return str(count/tot)

num = raw_input()
for i in range(0,int(num)):
    inp = raw_input().split()
    print 'Case #'+str(i+1)+': '+getProb(int(inp[0]),int(inp[1]),int(inp[2]))