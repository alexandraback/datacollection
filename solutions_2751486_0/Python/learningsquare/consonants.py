vowels = 'aeiou'
def numcons(str):
    longest = 0
    runningcount = 0
    for char in str:
        if char not in vowels:
            runningcount += 1
            longest = max(runningcount, longest)
        else:
            runningcount = 0
        
    return longest
        
def nvalue(str, n):
    nval = 0
    for i in range(len(str)):
        for j in range(len(str) + 1):
            if numcons(str[i:j]) >= n:
                nval += 1
    
    return nval
        
def readwrite(filename, fileoutname):
    output = []
    inputs = open(filename, 'r').readlines()[1:]
    for input in inputs:
        item = input.split(' ')
        output.append(nvalue(item[0], int(item[1])))
        
    fileout = open(fileoutname, 'w')
    for i in range(len(output)):
        fileout.write('Case #' + str(i+1) + ': ' + str(output[i]) + '\n')
        
readwrite('A-small-attempt0.in','outsmall.txt')