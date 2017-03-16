inputF = open('A-small-attempt4.in', 'r')
output = open('A-small-attempt4.out', 'w')

numCases = int(inputF.readline())

def isPalindrome(n):
    strN = str(n)
    revN = strN[::-1]
    if strN == revN:
        return True
    return False

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
    if target < 100:
        count = 10
        num = 10
    elif target < 1000:
        count = 29
        num = 100
    elif target < 10000:
        count = 138
        num = 1000
    elif target < 100000:
        count = 138 + 99 + 99 + 1
        num = 10000
    elif target < 1000000:
        count = 337 + 999 + 99 + 1
        num = 100000
    elif target == 1000000:
        return 337+999+99+1+999+999+1

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
