digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

digUniqLetter1 = {"Z": 0, "X": 6, "W": 2, "U": 4, "G": 8}
digUniqLetter2 = {"S": 7, "R": 3, "O": 1, "F": 5}

inFile = open("A-large.in")
outFile = open("1B.out", "w")

inFile.readline()

cnt = 1

for word in inFile:
    digCnt = [0 for i in range(10)]

    for letter in digUniqLetter1:
        dig = digUniqLetter1[letter]
        digCnt[dig] = word.count(letter)
        for let in digits[dig]:
            word = word.replace(let, "", digCnt[dig])

    for letter in digUniqLetter2:
        dig = digUniqLetter2[letter]
        digCnt[dig] = word.count(letter)
        for let in digits[dig]:
            word = word.replace(let, "", digCnt[dig])

    digCnt[9] = word.count("I")
    combined = [digCnt[i]*str(i) for i in range(10)]

    print("Case #" + str(cnt) + ":", "".join(sorted(combined)), file=outFile)

    cnt += 1

outFile.close()
