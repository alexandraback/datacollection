f = open('input.txt', 'r')
n = int(f.readline().strip())
out = open('output.txt', 'w')

def toBase(num, base):
    digits = []
    while num > 0:
        digits.insert(0, str(num % base))
        num //= base
    return int(''.join(digits))

def fromBase(num, base):
    answer = 0
    digits = list(str(num))
    for digit in digits:
        answer = base * answer + int(digit)
    return answer

def getBases(num):
    result = []
    for i in range(2, 11):
        result.append(fromBase(num, i))
    return result


def getDivisor(num):
    if num%2 == 0:
        return 2
    for i in range(3, int(num**0.25)+1,2):
        if num%i == 0:
            return i
    return -1
        


for i in range(n):
    inputStr = f.readline().strip().split(' ')
    jLength = int(inputStr[0])
    jNum = int(inputStr[1])
    results = []
    count = 0
    out.write("Case #" + str(i+1) + ":\n")
    totalPermutations = 2**(jLength-2)
    for i in range(1,totalPermutations):
        perm = 10**(jLength-1) + 1 + toBase(i, 2) * 10
        if count >= jNum:
            break;
        allBases = getBases(perm)
        currentPermBases = []
        isJamcoin = True
        for base in allBases:
            divisor = getDivisor(base)
            if (divisor == -1):
                isJamcoin = False
                break;
            else:
                currentPermBases.append(str(divisor))
        if isJamcoin:
            count += 1
            result = str(perm) + " " + " ".join(currentPermBases)
            out.write(result + "\n")
            print(result)
            
    
        


out.close()
f.close()


