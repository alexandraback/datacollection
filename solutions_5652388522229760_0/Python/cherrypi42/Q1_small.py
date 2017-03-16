
fileout = open('small.out',"w")

with open('small.in') as file:
    T = int(file.readline())
    
    for case in range(1, T+1):
        charset = set("1234567890")
        trotset = set()
        N = int(file.readline())
        
        if N == 0:
            fileout.write("Case #" + str(case) + ": " + "INSOMNIA")
       
        else:
            i = 0
            while charset != trotset:
                i += 1
                trotset = trotset.union(str(N * i))
            fileout.write("Case #" + str(case) + ": " + str(N * i))
        
        
        fileout.write("\n")
        
        
    
fileout.close()
