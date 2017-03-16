from sets import Set 
filein = open('A-large.in.txt', 'r')
fileout = open('A-large.out.txt', 'w')
numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
letters = "ZXCVBNMASDFGHJKLQWERTYUIOP"
T = int(filein.readline())
for t in range(T):
    fileout.write('Case #%d: ' % (t + 1))
    inp = filein.readline()
    result = []
    bag = {}
    for i in letters:
    	bag[i] = 0
    for i in inp:
    	if  i in bag:
    		bag[i] += 1
    num2 = bag['W']
    num0 = bag['Z']
    num6 = bag['X']
    # num5 = bag['F']
    # num7 = bag['V'] - bag['F']
    num8 = bag['G']
    num3 = bag['H'] - num8
    num4 = bag['R'] - num3 - num0
    num5 = bag['F'] - num4
    num7 = bag['V'] - num5
    num1 = bag['O'] - num0 - num2 - num4
    num9 = bag['I'] - num5 - num6 - num8
    result += [0]*num0
    result += [1]*num1
    result += [2]*num2
    result += [3]*num3
    result += [4]*num4
    result += [5]*num5
    result += [6]*num6
    result += [7]*num7
    result += [8]*num8
    result += [9]*num9
    for  i in result:
    	fileout.write(str(i))
    fileout.write("\n")
    # fileout.write("\n")		

    
 
filein.close()
fileout.close()