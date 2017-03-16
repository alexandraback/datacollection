#Google Code Jam Qualification Round 2016
#Problem A. Counting Sheep

in_file = open('Input.txt',"r")
out_file = open('Output.txt', "w")

N = int(in_file.readline())
for i in range(1,N+1):
    a = int(in_file.readline())
    
    dig_list = ["0","1","2","3","4","5","6","7","8","9"]
    for n in range(1,101):
        for chr in str(n*a):
            if chr in dig_list:
                dig_list.remove(chr)
        if len(dig_list) == 0:
            break
            
    if len(dig_list) != 0:
        out_file.write("Case #"+str(i)+": "+"INSOMNIA"+"\n")
    else:
        out_file.write("Case #"+str(i)+": "+str(n*a)+"\n")
in_file.close()
out_file.close()