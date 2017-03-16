#Google Code Jam Qualification Round 2016
#Problem B. Revenge of the Pancakes
import io


in_file = open('Input.txt',"r")
out_file = open('Output.txt', "w")

N = int(in_file.readline())
for i in range(1,N+1):
    line = in_file.readline()
    line = line.rstrip('\n')
    
    list = []
    for chr in line:
        if chr == "-":
            list.append(-1)
        else:   # chr == "+"
            list.append(1)
    
    flipN = 0
    while -1 in list:
        if list[0] == 1:
            for index in range(0,len(list)):
                if list[index] == 1:
                    list[index] = -1
                else:
                    break
            flipN += 1
        else:
            lastm = (len(list) - 1) - list[::-1].index(-1)
            list = [-x for x in list[lastm::-1]] + list[lastm+1::]
            flipN += 1
            
     
    
    out_file.write("Case #"+str(i)+": "+str(flipN)+"\n")

in_file.close()
out_file.close()