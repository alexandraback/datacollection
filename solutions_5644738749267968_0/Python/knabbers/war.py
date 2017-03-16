def solve(file):    
    
    f = open(file,'r')
    lines = f.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    i = 1 # line number
    n = 1 # case number
    while nCases > 0:
        print("case: " + str(n))
        line = lines[i].replace('\n', "").split(" ")
        N = int(line[0])
        line = lines[i+1].replace('\n', "").split(" ")
        a = list(map(float, line))
        line = lines[i+2].replace('\n', "").split(" ")
        b = list(map(float, line))        

        outf.write("Case #" + str(n) +": " + single(a,b))

        i += 3
        nCases -= 1
        n+=1

    f.close()
    outf.close()


def single(a,b):
    N = len(a)
    a.sort()
    b.sort()
    print(N)
    print(a)
    print(b)

##
##    ai=N-1
##    bi=0
##    dscore = 0
##    while True:
##        if a[ai]<b[bi]:
##            break
##        dscore += 1
##        ai -= 1
##        bi += 1

    
    ai=0
    bi=0
    oppscore=0
    while True:
        #pick smallest

        #bob picks next one
        while bi<N and b[bi]<a[ai]:
            bi+=1

        #if no more for bob
        if bi==N:
            break
        else:
            oppscore+=1
            ai+=1
            bi+=1
    score = N - oppscore




    bi=N-1
    dscore = 0
    while bi >= 0:
        #target bob's top one
        # wins first
        
        #find one for mary        
        ai=0
        while ai<len(a) and a[ai]<=b[bi]:
            ai += 1

        #check no win
        if ai>=len(a):
            #give up smallest
            del a[0]
        else:#win
            dscore += 1
            del a[ai]
        
        del b[bi]
        bi -= 1


    

    return str(dscore) + " " + str(score) + "\n"
        
