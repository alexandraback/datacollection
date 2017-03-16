n = input()
for i in range(n):
    ret = 0
    sum = 0
    for d in raw_input().rstrip().split(' ')[1]:
        ret = max(ret, sum)
        sum += 1 - int(d)
    print "Case #" + str(i + 1) + ":", ret

    
