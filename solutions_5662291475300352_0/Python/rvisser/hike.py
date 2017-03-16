#Hiking Deer

t = int(input())
for i in range(t):
    time = []
    start = []

    n = int(input())
    for j in range(n):
        tmp = input().split()
        d = int(tmp[0])
        h = int(tmp[1])
        m = int(tmp[2])

        for k in range(h):
            start.append(d)
            time.append(m+k)


    #Now, do prob with hikers
    if (len(time) <= 1):
        ans = 0
    else:
        #At least 2 hikers

        if (start[0] == start[1]):
            if time[0]==time[1]:
                ans = 0
            else:
                s = max(time[0], time[1])
                f = min(time[0], time[1])
                #Check if can make it with 0:
                dist = start[0] + (360*(f/s))/(1-(f/s))
                #print(dist)
                if dist > 360:
                    ans = 0
                else:
                    ans = 1
        else:
            #Different speeds
            if (time[0]==time[1]):
                ans = 0
            
            elif start[0] < start[1] and (time[1] < time[0]):
                #Faster already ahead
                s = max(time[0], time[1])
                f = min(time[0], time[1])
                dist = start[0] + ((360-start[1]+start[0])*(f/s))/(1-(f/s))
                if dist > 360:
                    ans = 0
                else:
                    ans = 1
                    
            elif start[0] > start[1] and (time[1] > time[0]):
                s = max(time[0], time[1])
                f = min(time[0], time[1])
                dist = start[1] + ((360-start[0]+start[1])*(f/s))/(1-(f/s))
                if dist > 360:
                    ans = 0
                else:
                    ans = 1

            elif start[0] > start[1] and (time[1] < time[0]):
                #First one has headstart, but slower
                s = max(time[0], time[1])
                f = min(time[0], time[1])
                dist = start[0] + ((-start[1]+start[0])*(f/s))/(1-(f/s))
                #Distance when first two meet
                if dist > 360:
                    ans = 0
                else:
                    #Try again with new distance
                    newstart = dist
                    dist = newstart + (360*(f/s))/(1-(f/s))
                    #print(dist)
                    if dist > 360:
                        ans = 0
                    else:
                        ans = 1

            else:
                #First one has headstart, but slower
                s = max(time[0], time[1])
                f = min(time[0], time[1])
                dist = start[1] + ((-start[0]+start[1])*(f/s))/(1-(f/s))
                #Distance when first two meet
                if dist > 360:
                    ans = 0
                else:
                    #Try again with new distance
                    newstart = dist
                    dist = newstart + (360*(f/s))/(1-(f/s))
                    #print(dist)
                    if dist > 360:
                        ans = 0
                    else:
                        ans = 1
                

                
                

            
            
            #print("WAITING")
        
        

    print("Case #", i+1, ": ", ans, sep='')
        

    
