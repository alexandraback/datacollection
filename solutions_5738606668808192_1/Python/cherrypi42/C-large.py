fileout = open('C-large.out',"w")


with open('C-large.in') as file:
    T = int(file.readline())
    
    for case in range(1, T+1):
        [N, J] = file.readline().split()
        N, J = int(N), int(J)
        fileout.write("Case #" + str(case) + ":\n")
        num = list(str(10**(N - 1) + 1))
        d = [3, 2, 5, 2, 7, 2, 3, 2, 3]
        count = 0
        #add in 2 pairs
        for i in range(1,N - 4,2):
            if count == J:
                            break
                
            for j in range(i+2, N - 2, 2):
                if count == J:
                            break
                
                for k in range(2, N - 3, 2):
                    if count == J:
                            break
                
                    for l in range(k+2, N-1, 2):
                        thisnum = list(str(10**(N - 1) + 1))
                        thisnum[i] = "1"
                        thisnum[j] = "1"
                        thisnum[k] = "1"
                        thisnum[l] = "1"
                        fileout.write(str(''.join(thisnum)) + " ")
                        count += 1
                        for m in range(2, 11):
                           print int(''.join(thisnum), m) % d[m - 2], 
                        for p in d:
                            fileout.write(str(p) + " ")
                        fileout.write("\n")
                        if count == J:
                            break
                
        
        #add in 5 pairs
            
fileout.close()
