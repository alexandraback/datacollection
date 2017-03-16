fileout = open('C-small.out',"w")


with open('C-small.in') as file:
    T = int(file.readline())
    
    for case in range(1, T+1):
        [N, J] = file.readline().split()
        N, J = int(N), int(J)
        fileout.write("Case #" + str(case) + ":\n")
        num = list(str(10**(N - 1) + 1))
        d = [3, 2, 5, 2, 7, 2, 3, 2, 3]
        count = 0
        #add in 2 pairs
        for i in range(1, N - 4):
            thisnum = list(str(10**(N - 1) + 1))
            if count == J:
                    break
            for j in range(i + 2, N - 2):
                thisnum = list(str(10**(N - 1) + 1))
                thisnum[i:i + 2] = ['1', '1']
                thisnum[j:j + 2] = ['1', '1']
                fileout.write(str(''.join(thisnum)) + " ")
                count += 1
#                print "\nANSWER: ", count
#                print "i, j: ", i, j
#                print "".join(thisnum)
                for m in range(2, 11):
                    print int(''.join(thisnum), m) % d[m - 2], 
                for l in d:
                    fileout.write(str(l) + " ")
                fileout.write("\n")
                if count == J:
                    break
                
                
                
        
        #add in 5 pairs
        
#        

#        
#        for l in d:
#            
#            
       
            
fileout.close()
