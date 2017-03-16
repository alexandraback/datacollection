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

"""
def getDivisor(num):
    if num%2 == 0:
        return 2
    sieve = [True] * num
    for i in range(3, int(num**0.5)+1, 2):
        if sieve[i]:
            sieve[i*i::2*i] = [False] * ((num-i*i-1)//(2*i)+1)
    primes = [i for i in range(3, num, 2) if sieve[i]]
    for p in primes:
        if (num%p == 0):
            return i
    return -1
"""

def getDivisor(num):
    if num%2 == 0:
        return 2
    for i in range(3, int(num**0.5)+1,2):
        if num%i == 0:
            return i
    return -1
        

def createBinaryPermutations(length):
    totalPermutations = 2**(length-2)
    permutations = []
    for i in range(1,totalPermutations):
        permutations.append(10**(length-1) + 1 + toBase(i, 2) * 10)
    return permutations

for i in range(n):
    inputStr = f.readline().strip().split(' ')
    jLength = int(inputStr[0])
    jNum = int(inputStr[1])
    allPermutations = createBinaryPermutations(jLength)
    results = []
    count = 0
    out.write("Case #" + str(i+1) + ":\n")
    for perm in allPermutations:
        if count >= 50:
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


