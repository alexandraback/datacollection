def jumpath(x, y):
    answer = ''
    if x < 0:
        for i in range(abs(x)):
            answer += 'EW'
    if x > 0:
        for i in range(x):
            answer += 'WE'
    if y < 0:
        for i in range(abs(y)):
            answer += 'NS'
    if y > 0:
        for i in range(y):
            answer += 'SN'
    return answer
    
def readwrite(filename, fileoutname):
    output = []
    inputs = open(filename, 'r').readlines()[1:]
    for input in inputs:
        item = input.split(' ')
        output.append(jumpath(int(item[0]), int(item[1])))
        
    fileout = open(fileoutname, 'w')
    for i in range(len(output)):
        fileout.write('Case #' + str(i+1) + ': ' + output[i] + '\n')
        
readwrite('B-small-attempt0.in', 'pogosmallout.txt')