filename = "B-small-attempt7"
infile = open("{}.in".format(filename))
outfile = open("{}.out".format(filename), 'w')


T = int(infile.readline())
for t in range(1,T+1):
    #print("\nCase {}".format(t))

    stars = 0
    levels = []
    N = int(infile.readline())
    for n in range(N):
        levels.append([int(x) for x in infile.readline().strip().split()]+[False])

    levels.sort(key=lambda x: x[0], reverse=True)
    levels.sort(key=lambda x: x[1])


    #print(levels)
        
    stars = 0
    completed = 0
    need = 0

    while levels:
        levels.sort(key = lambda x: x[1])
        while levels and levels[0][1] <= stars:
            if levels[0][2]:
                stars += 1
            else:
                stars += 2
            completed += 1
            levels.pop(0)
        if not levels:
            break
        need = levels[0][1]
        found = False
        for level in levels[::-1]:
            if level[2]:
                continue
            elif level[0] <= stars:
                stars += 1
                completed += 1
                level[2] = True
                found = True
            if need <= stars:
                break
        if not found:
            completed = None
            break
            

##    while levels:
##        while levels and levels[0][1] <= stars:
##            if levels[0][2]:
##                stars += 1
##            else:
##                stars += 2
##            completed += 1
##            print("completing 2 of {}".format(levels[0]))
##            print("stars = {}".format(stars))
##            levels.pop(0)
##        if not levels:
##            break
##        need = levels[0][1]
##        print("need", need)
##        found = True
##        while stars < need and found:
##            found = False
##            for level in levels[::-1]:
##                if level[0] <= stars and not level[2]:
##                    stars += 1
##                    completed += 1
##                    level[2] = True
##                    print("completing 1 of {}".format(level))
##                    print("stars = {}".format(stars))
##                    found = True
##                if stars >= need:
##                    break
##        if not found:
##            completed = None
##            break
        

    if completed == None:
        ans = "Too Bad"
    else:
        ans = completed
    outfile.write("Case #{}: {}\n".format(t, ans))
    print("Case #{}: {}".format(t, ans))
    
infile.close()
outfile.close()
