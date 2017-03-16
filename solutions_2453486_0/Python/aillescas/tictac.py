equivalente = {'X':1, 'O':2, 'T':10, '.':0}

def processData(fileName):
    f = open(fileName)
    
    T = int(f.readline().strip())

    for i in xrange(1, T+1):
        linea1 = [equivalente[val] for val in f.readline().strip()]
        linea2 = [equivalente[val] for val in f.readline().strip()]
        linea3 = [equivalente[val] for val in f.readline().strip()]
        linea4 = [equivalente[val] for val in f.readline().strip()]
        f.readline()

        diagonal1 = linea1[0] * linea2[1] * linea3[2] * linea4[3]
        diagonal2 = linea1[3] * linea2[2] * linea3[1] * linea4[0]
        col1 = linea1[0] * linea2[0] * linea3[0] * linea4[0]
        col2 = linea1[1] * linea2[1] * linea3[1] * linea4[1]
        col3 = linea1[2] * linea2[2] * linea3[2] * linea4[2]
        col4 = linea1[3] * linea2[3] * linea3[3] * linea4[3]

        result = ''
        mul1 = reduce(lambda x,y: x*y,linea1)
        mul2 = reduce(lambda x,y: x*y,linea2)
        mul3 = reduce(lambda x,y: x*y,linea3)
        mul4 = reduce(lambda x,y: x*y,linea4)
        muld1 = diagonal1
        muld2 = diagonal2

        if(mul1 == 1 or mul1 == 10 or
           mul2 == 1 or mul2 == 10 or
           mul3 == 1 or mul3 == 10 or
           mul4 == 1 or mul4 == 10 or
           col1 == 1 or col1 == 10 or
           col2 == 1 or col2 == 10 or
           col3 == 1 or col3 == 10 or
           col4 == 1 or col4 == 10 or
           muld1 == 1 or muld1 == 10 or
           muld2 == 1 or muld2 == 10) :
            result = 'X won'
        elif(mul1 == 80 or mul1 == 16 or
             mul2 == 80 or mul2 == 16 or
             mul3 == 80 or mul3 == 16 or
             mul4 == 80 or mul4 == 16 or
             col1 == 80 or col1 == 16 or
             col2 == 80 or col2 == 16 or
             col3 == 80 or col3 == 16 or
             col4 == 80 or col4 == 16 or
             muld1 == 80 or muld1 == 16 or
             muld2 == 80 or muld2 == 16) :
            result = 'O won'

        elif(mul1 * mul2 * mul3 * mul4 == 0):
            result = 'Game has not completed'
        else:
            result = 'Draw'

        #print mul1,mul2,mul3,mul4,col1,col2,col3,col4,muld1,muld2
        print 'Case #' + str(i) + ': ' + result     

processData('A-small-attempt0.in')
