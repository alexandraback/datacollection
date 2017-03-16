



FILE_PATH = "A-small-attempt0.in"
PATH_OUTPUT = "out.txt"


def parseFile():

    f = open( FILE_PATH, "r" )

    first = True
    mode = 1
    lis = []
    lis2 = []
    for line in f.readlines():
        line = line.rstrip("\n")
        if not line:
            continue

        if first:
            first = False
            continue

        lis2 = []
        for char in line.split(" "):
            lis2.append( char )
        lis.append(lis2)





    f.close()
    return lis

def main():
    x = parseFile()
    
    iteration = 1
    last_iteration = len(x)
    f = open( PATH_OUTPUT, "w")
    for lis in x:

        word = str(lis[0])
        n = int(lis[1])

        winCondition = 0
        # print word
        # Get all possible combinations
        combs = []
        for i in range( len(word) ):
            for j in range( i, len(word) ):
                combs.append(word[i:j+1])


        for comb in combs:
            if ( len(comb) < n ):
                continue
            count = countConsecutiveConsonants(comb)
            # print "comb: ", comb
            # print "cons: ", count
            if ( count >= n):
                winCondition += 1


        if ( iteration == last_iteration ):
            string = "Case #" + str(iteration) + ": " + str(winCondition)
        else:
            string = "Case #" + str(iteration) + ": " + str(winCondition) + "\n"
        f.write(string)
        iteration += 1


        # break

    f.close()

def countConsecutiveConsonants( word ):
    actualCount = 0
    maxCount = -1
    for char in word:
        if ( char != "a" and char != "e" and char != "i" and char != "o" and char != "u"):
            actualCount += 1
        else:
            actualCount = 0

        if actualCount > maxCount:
            maxCount = actualCount

    return maxCount



if __name__ == "__main__":
    main()