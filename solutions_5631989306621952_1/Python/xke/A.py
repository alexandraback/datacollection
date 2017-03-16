import math

inputfile = open('A-large.in')
outputfile = open('A-large.out.txt', 'w')

# function for parsing the data
def data_parser(inputStr):

    inputStr = inputStr.strip()
    listStr = list(inputStr)


    lastWord = listStr[0]

    # iterate through later ones
    for char in listStr[1:len(listStr)]:
      if char >= lastWord[0]:
        lastWord = char + lastWord
      else:
        lastWord = lastWord + char
      #lastChar = char

    return lastWord


#skip first line
#next(inputfile)

#read first line:
num_cases = int(inputfile.readline())

for i in range(0, num_cases):
    input = inputfile.readline()
    output_line = "Case #" + str(i+1) + ": " + data_parser(input)
    print output_line
    outputfile.writelines(output_line+"\n")

inputfile.close()
outputfile.close()
