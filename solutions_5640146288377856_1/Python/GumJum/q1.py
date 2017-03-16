#q2

def file2list(filename):
    l = []
    with open(filename) as fp:
        for line in fp:
            l.append(line)
    return l

from operator import mul

def writeData(data):
    f = open('test.out', 'w')
    s = ''
    for i in range(len(data)):
        s += 'Case #' + str(i + 1) + ': '
        s += str(data[i])
        s += '\n'
    f.write(s[:-1])
    f.close()

def getAns(R, C, W):
    res = 0
    res = (C - 1)//W + W
    return res * R

def main():
    print 'read data...'
    data = file2list('A-large.in')
    T = int(data[0])
    data = data[1:]
    print 'iterations: ', T

    result = []
    print 'start computing...'
    
    for i in range(len(data)):
        l = data[i].split(' ')
        result.append(getAns(int(l[0]), int(l[1]), int(l[2])))
        print i, T

    print result
    writeData(result)
    return result
    
if __name__ == '__main__':
    test = main()
