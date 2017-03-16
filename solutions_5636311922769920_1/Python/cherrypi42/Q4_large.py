import math

fileout = open('D-large.out',"w")
mixedfeelings = set("+-")

with open('D-large.in') as file:
    T = int(file.readline())
    
    for case in range(1, T+1):
        print "case", case
        [K, C, S] = file.readline().split()
        K, C, S = int(K), int(C), int(S)
        if S < math.ceil(float(K)/C):
            fileout.write("Case #" + str(case) + ": IMPOSSIBLE\n")
        else:
            y = ""
            num = 1
            while num <= K:
                combo = 1
                for i in range(min(K,C)):
                    print "i, num", i, num
                    combo = combo + ((K ** i) * (num-1))
                    
                    num += 1
                    if num > K:
                        break  
                print "combo", combo
                y = y + " " + str(combo)
            fileout.write("Case #" + str(case) + ":" + y + "\n")   
            
fileout.close()
