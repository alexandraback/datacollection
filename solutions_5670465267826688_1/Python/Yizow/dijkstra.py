import sys
import itertools
import collections 

baseQuaternions = ['1','i','j','k']
quaternion = dict()
quaternion['1'] = dict(zip(baseQuaternions, baseQuaternions))
quaternion['i'] = dict(zip(baseQuaternions, ['i', '-1', 'k', '-j']))
quaternion['j'] = dict(zip(baseQuaternions, ['j', '-k', '-1', 'i']))
quaternion['k'] = dict(zip(baseQuaternions, ['k', 'j', '-i', '-1']))

quaternionInverse = dict()
quaternionInverse['1'] = dict(zip(baseQuaternions, ['1', '-i', '-j', '-k']))
quaternionInverse['i'] = dict(zip(baseQuaternions, ['i', '1', 'k', '-j']))
quaternionInverse['j'] = dict(zip(baseQuaternions, ['j', '-k', '1', 'i']))
quaternionInverse['k'] = dict(zip(baseQuaternions, ['k', 'j', '-i', '1']))


def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                L, X = inputFile.readline().split()
                L, X = int(L), int(X)
                origX = X
                origString = inputFile.readline().split()[0]
                # print L*X
                newString, newX = findCycle(origString)
                string, X = newString, X * newX

                # print '[' + string + ']'
                spelledRight = spelling(L, X, string)

                if spelledRight:
                    out = 'YES'
                    cf = calcCycleFactor(string)
                    _,i,j = spelledRight
                    print spelledRight[1], spelledRight[1] + spelledRight[2]
                    print calcProduct(string, 0, spelledRight[1]), calcProduct(string, spelledRight[1], spelledRight[1] + spelledRight[2]), calcProduct(string, spelledRight[1] + spelledRight[2], len(string)*X)
                    assert i+j < len(string)*X
                else:
                    out = 'NO'
                print testNum+1
                outputFile.write("Case #%d: %s" % (testNum+1, out))
                print 

def spelling(L, X, s):
    if len(s) <= 1: 
        print 'too small'
        return False

    k = None
    cycleFactor = calcCycleFactor(s)

    # total = '1'
    # for _ in range(X%4):
    #     total = multiply(total, cycleFactor)
    if calcProduct(s, 0, len(s) * X) != '-1':
        print 'no sum'
        return False

    repeat = min(X, 8)
    i_index, j_index = -1, -1
    
    i_index = find(s, 'i', repeat, 0)
    if i_index == -1 or i_index > repeat*len(s):
        return False
    
    while True:
        # print 'here'
        # print i_index, j_index
        j_index = find(s, 'j', repeat, i_index%len(s))
        if (j_index == -1) or (i_index + j_index > repeat*len(s)):
            # print 'MISSED J'
            increment = find(s, 'i', repeat, i_index, 'i')
            i_index += increment
            if (increment == -1) or (i_index > repeat*len(s)):
                print 'no j'
                return False
            continue
        # We now have potential i- and j- indices
        else:
            return True, i_index, j_index
            # print 'LOWW'
            while True:
                # print 'HHIGH'
                # print i_index, i_index+j_index, k
                if k == None:
                    # k = '1'
                    # for letter in s[(i_index+j_index)%len(s):]:
                    #     k = multiply(k, letter)
                    
                    # cyclesUsed = (i_index + j_index)/len(s) +1
                    # cyclesLeft = (X - cyclesUsed) % 4 # %4 because f(n)=[i,j,k]^n has period 4
                    # for _ in range(cyclesLeft):
                    #     k = multiply(k, cycleFactor)
                    k = calcProduct(s, i_index+j_index, len(s)*X)
                    # print k
                    oldKIndex = (i_index+j_index)
                else: 
                    # print 'calc K'
                    k = divide(k, calcProduct(s, oldKIndex, (i_index+j_index)))
                    # print 'done'

                if k == 'k':
                    return True, i_index, j_index
                else: 
                    increment = find(s, 'j', repeat, (i_index+j_index)%len(s), 'j')
                    j_index += increment
                    if (increment == -1) or (i_index + j_index > repeat*len(s)):
                        break
                    continue
            increment = find(s, 'i', repeat, i_index, 'i')
            i_index += increment
            if (increment == -1) or (i_index > repeat*len(s)):
                print 'no k'
                return False
            continue



# x, y are strings
def multiply(x, y):
    sign = (x[0] == '-') ^ (y[0] == '-')
    x = x[-1]
    y = y[-1]
    result = quaternion[x][y]
    if sign:
        result = '-' + result
    if len(result) == 3:
        result = result[-1]
    return result

# multiply(y, result) = x
def divide(x, y):
    sign = (x[0] == '-') ^ (y[0] == '-')
    x = x[-1]
    y = y[-1]
    result = quaternionInverse[x][y]
    if sign:
        result = '-' + result
    if len(result) == 3:
        result = result[-1]
    return result

def calcProduct(s, startIndex, endIndex):
    l = len(s)
    prefactor = '1'
    postfactor = '1'
    cycleFactor = calcCycleFactor(s)
    multiple = ((endIndex/l - startIndex/l -1)) % 4
    
    if endIndex / l == startIndex / l:
        for letter in s[startIndex:endIndex]:
            postfactor = multiply(postfactor, letter)
        return postfactor    

    for letter in s[startIndex%len(s):]:
        prefactor = multiply(prefactor, letter)
    for letter in s[:endIndex%len(s)]:
        postfactor = multiply(postfactor, letter)

    product = prefactor
    for _ in range(multiple):
        product = multiply(product, cycleFactor)
    product = multiply(product, postfactor)
    # shiftedS = s[startIndex:] + s[:startIndex]
    # end = (endIndex - startIndex) % len(s)
    # print prefactor, cycleFactor, multiple, postfactor
    return product

def find(s, quat, repeat, startIndex, initial='1'):
    shiftedS = s[startIndex:] + s[:startIndex]
    found = initial
    index = 1
    for letter in shiftedS*repeat:
        found = multiply(found, letter)
        if found == quat:
            return index
        index += 1
    return -1 

def findCycle(s):
    for length in factors(len(s)):
        if s[:length] * (len(s)/length) == s:
            return s[:length], len(s)/length
    

def factors(n):
    if n <= 3:
        return [1, n]
    f = list(set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
    f.sort()
    return f

def calcCycleFactor(s):
    cycleFactor = '1'
    for letter in s:
        cycleFactor = multiply(cycleFactor, letter)
    return cycleFactor

for x in baseQuaternions:
    for y in baseQuaternions:
        prod = multiply(x,y)
        div = divide(prod,x)
        assert y == divide(prod,x)

main()

# find i
#     find j
#     if cant find j, find next i
#         check k 
#             if not k, find next j
#         if not j, k, find next i
