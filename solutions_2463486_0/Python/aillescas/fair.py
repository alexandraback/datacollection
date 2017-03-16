
def getFairAndSquare():
    result = []
    for i in xrange(1,100):
        numero = i
        
        if len(str(numero)) == 1 or numero / 10 == numero % 10:
            cuadrado = str(numero * numero)

            primeraMitad = cuadrado[:len(cuadrado)/2]
            segundaMitad = cuadrado[len(cuadrado)/2:] if (len(cuadrado) % 2) == 0 else cuadrado[len(cuadrado)/2 + 1:]

            if primeraMitad == segundaMitad[::-1]:
                #print cuadrado
                result.append(int(cuadrado))
            #else:
    #print result
        
    for x in xrange(10,10000):
        pivote = x % 10
        resto = x / 10

        numero = int(str(resto) + str(pivote) + str(resto)[::-1]) if resto > 0 else pivote
        
        cuadrado = str(numero * numero)

        primeraMitad = cuadrado[:len(cuadrado)/2]
        segundaMitad = cuadrado[len(cuadrado)/2:] if (len(cuadrado) % 2) == 0 else cuadrado[len(cuadrado)/2 + 1:]

        if primeraMitad == segundaMitad[::-1]:
            #print cuadrado
            result.append(int(cuadrado))
        #else:
        #    print numero, cuadrado
        #print result
    
    return result


def processData(fileName):
    f = open(fileName)
    T = int(f.readline().strip())

    datos = getFairAndSquare()
    
    for i in xrange(1, T+1):
        A,B = [int(val) for val in f.readline().strip().split(' ')]
        
        indiceA = 0
        indiceB = 0
        incremento = 0
        for y in xrange(len(datos)):
            if datos[y] <= A:
                indiceA = y
            if datos[y] == A:
                incremento = 1
            if datos[y] <= B:
                indiceB = y

        print 'Case #' + str(i) + ': ' + str(indiceB - indiceA + incremento)
        
    


processData('C-small-attempt0.in')
