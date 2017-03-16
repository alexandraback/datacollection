import math

def betterRange(minimum, maximum):
    while minimum < maximum:
        yield minimum
        minimum += 1
        
def reverseNumber(n, partial=0):
    if n == 0:
        return partial
    return reverseNumber(n / 10, partial * 10 + n % 10)

def isPalindrome (num):
    return num == reverseNumber(num)

def isFairSquare (num):
    sqrt = math.sqrt(num)
    if int(sqrt) != sqrt:
        return False

    sqrt = int(sqrt)

    return isPalindrome(num) and isPalindrome(sqrt)

def getCases (raw):
    output = ""
    
    first = True
    lines = raw.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        if first:
            first = False
            continue
        
        if line == "" or line == " " * len(line):
            continue

        numbers = line.split(" ")

        output += str.format("Case #{0}: {1}\n", i, getFairSquares(int(numbers[0]), int(numbers[1])))

    print(output)
    with open("OUTPUT.txt", "w") as file:
        file.write(output)
        
        

def getFairSquares(minimum, maximum):
    count = 0
    fairSquares = []
    for num in betterRange(minimum, maximum + 1):
        if isFairSquare(num):
            count += 1
            fairSquares.append(num)

    return count
