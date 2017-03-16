#Google Code Jam Qualification Round 2016
#Problem B. Revenge of the Pancakes
import io
import math


in_file = open('Input.txt',"r")
out_file = open('Output.txt', "w")

N = int(in_file.readline())
for i in range(1,N+1):
    K,C,S = (int(x) for x in in_file.readline().split())
    
    if S * C < K:
        out_file.write("Case #"+str(i)+": "+"IMPOSSIBLE"+"\n")
    else:
        list = [1]*(math.ceil(K/C)*C)
        list[0:K] = range(1,K+1)
        checkstring = ""
        for trial in range(0,math.ceil(K/C)):
            check = 1
            for ind in range(0,C):
                check += (K**(C-1-ind)) * (list[trial*C+ind]-1)
            checkstring += " " + str(check)       
        
    
    
        out_file.write("Case #"+str(i)+":"+checkstring+"\n")

in_file.close()
out_file.close()