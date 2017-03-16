fh = open("B-large (1).in", "r")
fh2 = open("output.txt", "w")
testCases = fh.readline()
import math


def getNumberOfConnections(cars, anywhere):
    #print cars, anywhere
    #print "@@@@@@@@"
    if len(cars) == 0:
        return math.factorial(len(anywhere))
    
    f = cars[0][0]
    b = cars[0][-1]

    #If both letters are the same
    if f == b:
        bothLetters = []
        frontLetters = []
        backLetters = []

        bothLetters.append(f+b)

        toPop = []
        notPopped = []
        
        for i in range(1, len(cars)):
            if cars[i][0] == b:
                if cars[i][-1] == b:
                    bothLetters.append(cars[i])
                else:
                    frontLetters.append(cars[i])
                toPop.append(cars[i])
            elif cars[i][-1] == b:
                backLetters.append(cars[i])
                toPop.append(cars[i])
            else:
                notPopped.append(cars[i])
        if len(toPop) > 0:
            
            if len(frontLetters) > 1 or len(backLetters) > 1:
                return False
            if len(frontLetters) == 1:
                b2 = frontLetters[0][-1]
            else:
                b2 = f
            
            if len(backLetters) == 1:
                f2 = backLetters[0][0]
            else:
                f2 = b
            newCar = f2 + b2
            if f2 == b2:
                good = True
                for c in frontLetters:
                    for char in c:
                        if char != f2:
                            good = False
                for c in bothLetters:
                    for char in c:
                        if char != f2:
                            good = False
                for c in backLetters:
                    for char in c:
                        if char != f2:
                            good = False
                if good == False:
                    return False
            subproblem = getNumberOfConnections(notPopped + [newCar], anywhere)
            if subproblem != False:
                return subproblem * math.factorial(len(bothLetters))
            else:
                return False
        else:
            return getNumberOfConnections(notPopped, anywhere + [f+b])

    #Back letters
    bothLetters = []
    frontLetters = []
    backLetters = []

    toPop = []
    notPopped = []
    
    for i in range(1, len(cars)):
        if cars[i][0] == b:
            if cars[i][-1] == b:
                bothLetters.append(cars[i])
            else:
                frontLetters.append(cars[i])
            toPop.append(cars[i])
        elif cars[i][-1] == b:
            backLetters.append(cars[i])
            toPop.append(cars[i])
        else:
            notPopped.append(cars[i])


    if len(toPop) > 0:
        if len(backLetters) > 0 or len(frontLetters) > 1:
            return False
        if len(frontLetters) == 1:
            newCar = f + frontLetters[0][-1]
            if f == frontLetters[0][-1]:
                good = True
                for c in frontLetters:
                    for char in c:
                        if char != f:
                            good = False
                for c in bothLetters:
                    for char in c:
                        if char != f:
                            good = False
                for c in backLetters:
                    for char in c:
                        if char != f:
                            good = False
                if good == False:
                    return False
            subproblem = getNumberOfConnections(notPopped + [newCar], anywhere)
            if subproblem != False:
                return subproblem * math.factorial(len(bothLetters))
            else:
                return False
        else:
            newCar = f + b
            if f == b:
                good = True
                for c in frontLetters:
                    for char in c:
                        if char != f:
                            good = False
                for c in bothLetters:
                    for char in c:
                        if char != f:
                            good = False
                for c in backLetters:
                    for char in c:
                        if char != f:
                            good = False
                if good == False:
                    return False
            subproblem = getNumberOfConnections(notPopped + [newCar], anywhere)
            if subproblem != False:
                return subproblem * math.factorial(len(bothLetters))
            else:
                return False
    else:
        #Front letters
        bothLetters = []
        frontLetters = []
        backLetters = []

        toPop = []
        notPopped = []
        
        for i in range(1, len(cars)):
            if cars[i][0] == f:
                if cars[i][-1] == f:
                    bothLetters.append(cars[i])
                else:
                    frontLetters.append(cars[i])
                toPop.append(cars[i])
            elif cars[i][-1] == f:
                backLetters.append(cars[i])
                toPop.append(cars[i])
            else:
                notPopped.append(cars[i])
                
        if len(toPop) > 0:
            if len(frontLetters) > 0 or len(backLetters) > 1:
                return False
            if len(backLetters) == 1:
                newCar = backLetters[0][0] + b
                if backLetters[0][0] == b:
                    good = True
                    for c in frontLetters:
                        for char in c:
                            if char != b:
                                good = False
                    for c in bothLetters:
                        for char in c:
                            if char != b:
                                good = False
                    for c in backLetters:
                        for char in c:
                            if char != b:
                                good = False
                    if good == False:
                        return False
                subproblem = getNumberOfConnections(notPopped + [newCar], anywhere)
                if subproblem != False:
                    return subproblem * math.factorial(len(bothLetters))
                else:
                    return False
            else:
                newCar = f + b
                if f == b:
                    good = True
                    for c in frontLetters:
                        for char in c:
                            if char != f:
                                good = False
                    for c in bothLetters:
                        for char in c:
                            if char != f:
                                good = False
                    for c in backLetters:
                        for char in c:
                            if char != f:
                                good = False
                    if good == False:
                        return False
                subproblem = getNumberOfConnections(notPopped + [newCar], anywhere)
                if subproblem != False:
                    return subproblem * math.factorial(len(bothLetters))
                else:
                    return False
        #
        else:
            return getNumberOfConnections(cars[1:], anywhere + [cars[0]])
            
        
    return 1

for testCase in xrange(int(testCases)):
    print testCase
    N = int(fh.readline().split()[0])
    
    cars = fh.readline().split()
    #print cars
    letters = dict()
    for c in cars:
        for char in c:
            if char in letters:
                letters[char] += 1
            else:
                letters[char] = 1
    possible = True
    for i in range(len(cars)):
        middleLetter = ""
        if len(cars[i]) >= 3:
            lettersInC = dict()
            for j in range(len(cars[i])): #char = cars[i][j]
                if cars[i][j] in lettersInC:
                    lettersInC[cars[i][j]] += 1
                    if cars[i][j] != cars[i][j - 1]:
                        possible = False
                        break
                else:
                    lettersInC[cars[i][j]] = 1
            for char in lettersInC:
                if char != cars[i][0] and char != cars[i][-1]:
                    if lettersInC[char] < letters[char]:
                        possible = False
                        break
                    middleLetter = "-"
                    
        if possible:
            cars[i] = cars[i][0] + middleLetter + cars[i][-1]
        else:
            break
                        
    for c in cars:
        if len(c) >= 3:
            if c[0] == c[-1]:
                possible = False
                break
    

    #print N, cars
    if possible:
        ans = getNumberOfConnections(cars, [])
        if ans == False:
            ans = 0
    else:
        ans = 0

    #print ans

    #print "_________________________________________"
    # ans = 
    fh2.write("Case #" + str(testCase + 1) + ": " + str(ans) + "\n")
    

fh.close()
fh2.close()
    
    
    
        
