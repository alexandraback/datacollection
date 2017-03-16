import math

inputfile = open('B-large.in')
outputfile = open('B-large.out.txt', 'w')

# function for parsing the data
def data_parser(listNumbers):

    # make sure to sort int's
    listNumbers = sorted(listNumbers, key=int) # sort and cancel doubles

   # print listNumbers

    lastNumber = listNumbers[0]
    listMissing = []
    numCount = 1

    for number in listNumbers[1:len(listNumbers)]:
      if number == lastNumber: 
        numCount = numCount + 1

      else:
        # different number!
        if numCount % 2 == 1: # odd count of numbers, add to the missing list!
          listMissing.append(lastNumber)
   
        numCount = 1
      
      lastNumber = number


    if numCount % 2 == 1: # odd count of numbers, add to the missing list!
      listMissing.append(lastNumber)

    return ' '.join(sorted(listMissing, key=int))



# --------------------------------------------


#skip first line
#next(inputfile)

#read first line:
num_cases = int(inputfile.readline())


for i in range(0, num_cases):
    
    N = int(inputfile.readline())

    listNumbers = [] # clear set

    for j in range(0, 2*N-1):

      listNumbers = listNumbers + inputfile.readline().strip().split()

    output_line = "Case #" + str(i+1) + ": " + data_parser(listNumbers)
    print output_line
    outputfile.writelines(output_line+'\n')

inputfile.close()
outputfile.close()
