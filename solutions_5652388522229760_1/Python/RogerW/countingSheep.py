def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        N = int(raw_input())

        lastNum = getLastNamedNumber(N)

        print "Case #{}: {}".format(i, lastNum)

def getLastNamedNumber(N):
    if N == 0:
        return "INSOMNIA"

    # multiplier = 1
    currNum = N
    isDigitsSeen = [False] * 10
    while True:
        for digit in numToDigits(currNum):
            isDigitsSeen[digit] = True

        if all(isDigitSeen == True for isDigitSeen in isDigitsSeen):
            return currNum

        currNum += N

def numToDigits(num):
    return [int(i) for i in str(num)]

if __name__ == '__main__':
    main()
