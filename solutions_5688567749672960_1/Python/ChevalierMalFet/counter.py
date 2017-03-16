inputF = open('A-large.in', 'r')
output = open('A-large.out', 'w')

numCases = int(inputF.readline())

def isPalindrome(n):
    strN = str(n)
    revN = strN[::-1]
    if strN == revN:
        return True
    return False

def getToRightDigits(n):
    numDigits = len(str(n))
    accum = 10
    for i in range(1,numDigits-1):
        accum += int('9'*((i+1)/2)) + 1 + int('9'*((i+2)/2))
    return accum

def countToN(n):
    target = n
    count = 0
    num = 0
    strN = str(n)
    revN = strN[::-1]
    fix = 0
    backHalf = strN[(len(strN)/2):]
    if backHalf == '0'*len(backHalf):
        fix = 1
        target = n-1
        strN = str(target)
        revN = strN[::-1]
    
    # Get to the right number of digits as fast as possible
    if target <= 19:
        return n
    
    count = getToRightDigits(target)
    num = 10**(len(strN)-1)

    # Once at right number of digits, count up the least significant half to
    # the correct number, swap, and then count up the most significant
    lowCount = int(revN[(len(revN)+1)/2:])
    num += lowCount
    count += lowCount
    if not isPalindrome(num):
        count += 1
    num = int(str(num)[::-1])

    count += target-num
    return fix + count
    
        

for i in range(numCases):
    n = int(inputF.readline())

    result = countToN(n)

    output.write('Case #' + str(i+1) + ': ')
    output.write(str(result) + '\n')




inputF.close()
output.close()
