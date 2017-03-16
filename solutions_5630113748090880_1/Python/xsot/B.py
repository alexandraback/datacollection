for t in range(1, int(raw_input())+1):
    n = int(raw_input())
    heights = []
    arr = []
    for i in range(2*n-1):
        line = map(int, raw_input().split())
        arr += line
        heights += [line[0]]
        
    arr.sort()
    missing = []
    count = 0
    p = -1
    for c in arr+[-1]:
        count += 1
        if c!= p:
            if count%2 == 0:
                missing += [p]
            count = 1
        p = c
    
    print "Case #%d: "%t + " ".join(map(str, missing))