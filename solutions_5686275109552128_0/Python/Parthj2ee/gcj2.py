t = int(raw_input())
for l in range(t):
    s = int(raw_input())
    numbers = map(int, raw_input().split())
    time = max(numbers)
    optime =1
    while(time > optime):
        total =0
        for m in numbers:
            total += (m-1)//optime 
        total += optime
        if(time > total):
            time = total
        optime+=1

    print "Case #%d: %d" %(l+1,time)
    
