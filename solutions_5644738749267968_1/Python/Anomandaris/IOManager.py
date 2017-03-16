def writeOutput(strings,fileName):
    file = open(fileName,"w")
    for i,s in enumerate(strings):
        file.write("Case #" + str(i+1) + ": " + s + "\n")
    file.close()
    
def readInput(fileName):
    file = open(fileName,"r")
    content = []
    
    for s in file:
        content.append(s.rstrip('\n'))
        
    return int(content[0]), content[1:]

def formatInput(strings,sectionFormat):
    
    linesPerSection = sum(sectionFormat)
    lines = len(strings)
    sections = lines/linesPerSection
    
    if sections != lines/float(linesPerSection):
        raise Exception("Incorrect number of lines!")
    
    formattedInput = []
    for i in range(0,lines,linesPerSection):
        section = []
        index = 0
        for j in range(len(sectionFormat)):
            l = sectionFormat[j]
            section.append(strings[i+index:i+index+l])
            index += l
        formattedInput.append(section)
        
    return formattedInput