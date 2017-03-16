T= int(raw_input())
    
for test in range(1,T+1):
    shylevel=0
    friends=0
    ovation=0
    for number in map(int,(raw_input()).split()[1]):
        if ovation<shylevel:
            friends+=shylevel-ovation
            ovation=shylevel
        ovation+=number
        shylevel+=1


    print "Case #{0}: {1}".format(test,friends)
    
