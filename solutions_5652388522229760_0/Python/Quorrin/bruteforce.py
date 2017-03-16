f = open('input.in', 'r')
n = int(f.readline().strip())
out = open('output.txt', 'w')

def getDigits(num):
    digit = []
    if (num == 0):
        digit.append(0)
    else:    
        while(num > 0):
            lastDigit = num%10
            digit.append(lastDigit)
            num //= 10
    digit = stripDuplicates(digit)
    return digit

def stripDuplicates(dups):
    digits = {}
    rets = []
    for j in range (len(dups)):
        if not (dups[j] in digits):
            digits[dups[j]] = True
            rets.append(dups[j])
    return rets

for i in range(n):
    inputNum = int(f.readline())
    numberSet = {}
    inputDigits = getDigits(inputNum)
    for j in range(len(inputDigits)):
        numberSet[inputDigits[j]] = True
    print(inputDigits)
    for j in range(2, 1000001):
        if j == 1000000:
            print("INSOMNIA")
            out.write("Case #" + str(i+1) + ": INSOMNIA\n")
        inputDigits = getDigits(inputNum * j)
        for k in range(len(inputDigits)):
            if not (inputDigits[k] in numberSet):
                numberSet[inputDigits[k]] = True
        if (len(numberSet.values()) == 10):
            print(inputNum * j)
            out.write("Case #" + str(i+1) + ": " + str(inputNum * j) + "\n")
            break

out.close()        
    

