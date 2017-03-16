spelledDigits = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

T = int(input())
for i in range(T):
    scrambledNumber = list(input())

    correctDigits = []
    unique = {2:['W'], 6:['X'], 8:['G'], 0:['Z'], 4:['U']}

    for digit in unique:
        for uniqueLetter in unique[digit]:
            while uniqueLetter in scrambledNumber:
                #print("Trying " + str(digit))
                correctDigits.append(digit)
                for letter in spelledDigits[digit]:
                    scrambledNumber.remove(letter)

    # SECOND PASS
    unique = {7:['S'], 5:['F'], 3:['T'], 1:['O']}

    for digit in unique:
        while set(unique[digit]).issubset(set(scrambledNumber)):
            correctDigits.append(digit)
            for letter in spelledDigits[digit]:
                scrambledNumber.remove(letter)

    #print(scrambledNumber)
    # CLEANUP
    while len(scrambledNumber) > 0:
        correctDigits.append(9)
        for letter in spelledDigits[9]:
            scrambledNumber.remove(letter)

    
    #print(scrambledNumber)
    '''currentDigit = 0
    while currentDigit <= 9:
        if currentDigit in unique: 
            currentDigit += 1
            continue

        doAllMatch = True
        tmp = []

        for letter in spelledDigits[currentDigit]:
            if letter not in scrambledNumber:
                doAllMatch = False
                currentDigit += 1
                scrambledNumber.extend(tmp)
                break

            else:
                scrambledNumber.remove(letter)
                tmp.append(letter)

        if doAllMatch:
            correctDigits.append(currentDigit)'''

    correctDigits.sort()
    correctDigits = map(str, correctDigits)
    #print(str(''.join(correctDigits)))
    print("Case #{}: {}".format(i+1, str(''.join(correctDigits))))
    if len(scrambledNumber) > 0:
        print(scrambledNumber)