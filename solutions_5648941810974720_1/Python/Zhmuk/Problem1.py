################## Elena Khusainova #####################

################## Libraries ############################


######################### Main ##########################
filename = "A-large.in"

f = open(filename, "r")
data = f.read()
f.close()

data = data.split("\n")


T = data[0]
data.remove(T)
del data[-1]

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

for i in range(len(data)):
    temp = list(data[i])
    answer = []

    while 'Z' in temp:
        temp.remove('Z')
        temp.remove('E')
        temp.remove('R')
        temp.remove('O')
        answer += [0]
    while 'X' in temp:
        temp.remove('S')
        temp.remove('I')
        temp.remove('X')
        answer += [6]
    while 'S' in temp:
        temp.remove('S')
        temp.remove('E')
        temp.remove('V')
        temp.remove('E')
        temp.remove('N')
        answer += [7]
    while 'G' in temp:
        temp.remove('E')
        temp.remove('I')
        temp.remove('G')
        temp.remove('H')
        temp.remove('T')
        answer += [8]
    while 'W' in temp:
        temp.remove('T')
        temp.remove('W')
        temp.remove('O')
        answer += [2]
    while 'V' in temp:
        temp.remove('F')
        temp.remove('I')
        temp.remove('V')
        temp.remove('E')
        answer += [5]
    while 'U' in temp:
        temp.remove('F')
        temp.remove('O')
        temp.remove('U')
        temp.remove('R')
        answer += [4]
    while 'I' in temp:
        temp.remove('N')
        temp.remove('I')
        temp.remove('N')
        temp.remove('E')
        answer += [9]
    while 'H' in temp:
        temp.remove('T')
        temp.remove('H')
        temp.remove('R')
        temp.remove('E')
        temp.remove('E')
        answer += [3]
    while 'O' in temp:
        temp.remove('O')
        temp.remove('N')
        temp.remove('E')
        answer += [1]

    answer = sorted(answer)
    answer = [str(s) for s in answer]

        
 
        
    with open("Problem1Large_out.txt", "a") as myfile:
        myfile.write('Case #'+str(i+1)+': '+''.join(answer)+'\n')
    myfile.close()

        

