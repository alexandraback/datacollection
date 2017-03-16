#Central positions can't be higher than any of the edges
def lawnsViable (lawnsRaw):
    currentLawn = ""
    rows = 0
    currentPosition = 1
    first = True
    output = ""
    
    for line in lawnsRaw.split("\n"):
        if first:
            first = False
            continue

        if line == "":
            continue

        if rows == 0:
            rows = int(line[0:line.find(' ')]) + 1

        currentLawn += line + "\n"

        rows -= 1
        if rows == 0:
            output += "Case #{0}: {1}\n".format(currentPosition, lawnViable(currentLawn))
            currentLawn = ""
            currentPosition += 1

    print(output)
    with open("OUTPUT.txt", "w") as file:
        file.write(output)
            

def lawnViable (lawnRaw):
    if lawnRaw[-1] != "\n":
        lawnRaw += "\n"
    
    rows = 0
    columns = 0
    idealLawn = []

    currentNumber = ""
    currentRow = []
    
    for i in range(len(lawnRaw)):
        char = lawnRaw[i]
        if char in [" ", "\n"]:
            if currentNumber == "":
                continue
            
            if rows == 0:
                rows = int(currentNumber)
                currentNumber = ""
                continue
            
            if columns == 0:
                columns = int(currentNumber)
                currentNumber = ""
                continue
            
            currentRow.append(int(currentNumber))
            currentNumber = ""
            
            if len(currentRow) == columns:
                idealLawn.append(currentRow)
                currentRow = []
            
        else:
            currentNumber += char
    
    lawn = []
    for row in range(rows):
        currentRow = []
        for column in range(columns):
            currentRow.append(100)
        lawn.append(currentRow)

    for row in range(rows):
        maximum = 0
        for column in range(columns):
            if idealLawn[row][column] > maximum:
                maximum = idealLawn[row][column]

        for column in range(columns):
            lawn[row][column] = min(lawn[row][column], maximum)
        
    for column in range(columns):
        maximum = 0
        for row in range(rows):
            if idealLawn[row][column] > maximum:
                maximum = idealLawn[row][column]
                
        for row in range(rows):
            lawn[row][column] = min(lawn[row][column], maximum)

    if lawn == idealLawn:
        return "YES"

    else:
        return "NO"
                

    

    

                
    
