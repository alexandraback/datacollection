firstnumtostr = {
    0:"ZERO",
    2:"TWO",
    4:"FOUR",
    6:"SIX",
    8:"EIGHT",
    }

firstkey = {
    "Z":0,
    "W":2,
    "U":4,
    "X":6,
    "G":8,
    }

secondnumtostr = {
    1:"ONE",
    3:"THREE",
    5:"FIVE",
    7:"SEVEN",}

secondkey = {
    "O":1,
    "T":3,
    "F":5,
    "S":7,
    }

thirdnumtostr = {
    9:"NINE",
    }

thirdkey = {
    "N":9,
    }

def remove(line, integer, dic):
    string = dic[integer]
    for char in string:
        pos = line.find(char)
        line = line[:pos] + line[(pos+1):]
    return line
    
def run(line):
    ret_int = []
    for key in firstkey.keys():
        while(key in line):
            line = remove(line, firstkey[key], firstnumtostr)
            ret_int.append(firstkey[key])

    for key in secondkey.keys():
        while(key in line):
            line = remove(line, secondkey[key], secondnumtostr)
            ret_int.append(secondkey[key])

    for key in thirdkey.keys():
        while(key in line):
            line = remove(line, thirdkey[key], thirdnumtostr)
            ret_int.append(thirdkey[key])


    ret_int.sort()
    return "".join(str(x) for x in ret_int)

fi = open("A-large.in", "r")
fo = open("output.txt", "w")
templines = fi.readlines()
T = int(templines[0])
for i in range(T):
    answer = run(templines[i+1])
    fo.write("Case #" + str(i+1) + ": " + answer + "\n")
fi.close()
fo.close()
