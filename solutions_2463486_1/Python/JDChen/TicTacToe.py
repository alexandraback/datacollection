# File input
#input = open('H:/winprofile/desktop/a.in','r')
input = open('C:/Users/Asus/Desktop/a.in','r')
outputString = ""

#Define function
def check(lines):
    #Horizontal
    for i in range(0,4):
        xCount = 0
        oCount = 0
        for j in range(0,4):
            if lines[i][j]=='X':
                xCount=xCount + 1
            elif lines[i][j]=='O':
                oCount=oCount + 1
            elif lines[i][j]=='T':
                xCount=xCount + 1
                oCount=oCount + 1
        if xCount==4:
            return 'X won'
        elif oCount==4:
            return 'O won'
    #Vertical
    for j in range(0,4):
        xCount = 0
        oCount = 0
        for i in range(0,4):
            if lines[i][j]=='X':
                xCount=xCount + 1
            elif lines[i][j]=='O':
                oCount=oCount + 1
            elif lines[i][j]=='T':
                xCount=xCount + 1
                oCount=oCount + 1
        if xCount==4:
            return 'X won'
        elif oCount==4:
            return 'O won'
    #Diagonal left
    xCount = 0
    oCount = 0
    for i in range(0,4):
        if lines[i][i]=='X':
            xCount=xCount + 1
        elif lines[i][i]=='O':
            oCount=oCount + 1
        elif lines[i][i]=='T':
            xCount=xCount + 1
            oCount=oCount + 1
    if xCount==4:
        return 'X won'
    elif oCount==4:
        return 'O won'
    #Diagonal right
    xCount = 0
    oCount = 0
    for i in range(0,4):
        if lines[i][3-i]=='X':
            xCount=xCount + 1
        elif lines[i][3-i]=='O':
            oCount=oCount + 1
        elif lines[i][3-i]=='T':
            xCount=xCount + 1
            oCount=oCount + 1
    if xCount==4:
        return 'X won'
    elif oCount==4:
        return 'O won'
    #Draw
    for i in range(0,4):
        for j in range(0,4):
            if lines[i][j]=='.':
                return 'Game has not completed'
    return 'Draw'
      
# Calculation
numCase = int(input.readline().replace('\n',''))

for i in range(1,numCase+1):
    lines =[]
    for j in range(0,4):
        line = input.readline().replace('\n','')
        lines.append(line)
    input.readline()
    outputString = outputString + 'Case #' + str(i) + ': ' + check(lines)+ '\n'


#File output
#output = open('H:/winprofile/desktop/a.out','w')
output = open('C:/Users/Asus/Desktop/a.out','w')
output.write(outputString)
input.close()
output.close()
