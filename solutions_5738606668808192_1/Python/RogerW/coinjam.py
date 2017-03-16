import math

# idea:
# 110011 = 11 * 10001
# so 110011 will never be prime in base 2~10

def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        N, J = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
        print "Case #{}:".format(i)   



        divisor = 3 # 11 in 2-based
        # divisor = 3 + 2*i

        lowerBound = int(math.pow(2, N-1))      # lowerBound < validNum
        upperBound = int(math.pow(2, N))        # validNum < upperBound
        
        minValidMult = lowerBound / divisor   # divisor * minValidMult < minValidNum
        if minValidMult % 2 == 0:
            minValidMult += 1
        else:
            minValidMult += 2
        # debug
        # if divisor * minValidMult <= lowerBound:
        #     print "error"
        #     print divisor * minValidMult

        maxValidMult = upperBound / divisor
        if minValidMult % 2 == 0:
            maxValidMult -= 1
        else:
            maxValidMult -= 2



        validMult = minValidMult    # validMult % 2 == 1
        validNumCount = 0
        # important: divisor * (minValidMult +2n) may not be valid
        # because (x+1) * (x+1) = x^2 + 2x + 1   not x^3 + 1 (1001)
        # so 11 * 11 (base 2) may not be dividable whe x >= 3
        while True:
            num = divisor * validMult
            if checkNumberValid(num):
                # is valid
                validNumCount += 1
                print bin(num)[2:],
                for i in xrange(3, 12):
                    print i,
                print
            # else:
            #     print num, bin(num)[2:]

            if validNumCount == J:
                break

            validMult += 2
            if validMult > maxValidMult:
                break

def checkNumberValid(num):
    isValid = True
    for base in xrange(2,11):
        if decToBinToBaseN(num, base) % (base+1) != 0:
            isValid = False
            break
    return isValid

def decToBinToBaseN(dec, base):
    # print dec
    binaryStr = bin(dec)[2:]
    # print binaryStr
    numInBaseN = 0
    for digit in binaryStr:
        numInBaseN *= base
        if digit == '1':
            numInBaseN += 1

    # print numInBaseN
    return numInBaseN

if __name__ == '__main__':
    main()
