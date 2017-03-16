for T in range(int(input())):
    D = int(input())
    P = map(int, input().split())
    plate_count = [0]*1001
    for plate in P:
        plate_count[plate] += 1
    
    result = max(i for i, c in enumerate(plate_count) if c > 0)
    split_minutes = 0
    for i in range(1000, 0, -1):
        if plate_count[i] > 0:
            result = min(result, split_minutes + i)
            
            split_minutes += plate_count[i]
            plate_count[i//2] += plate_count[i]
            plate_count[i - i//2] += plate_count[i]
            
    print ("Case #%d: %d" % (T+1, result))
            