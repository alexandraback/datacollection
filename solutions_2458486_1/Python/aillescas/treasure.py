
def posible(keys, chests):
    keysNecesarias = []
    keysDisponibles = list(keys)
    
    chestsNuevo = [list(chests[val]) for val in chests.keys() if chests[val][0] > 0]
    nuevas = True
    while nuevas:
        nuevas = False
        for clave in chestsNuevo:
            if clave[0] in keysDisponibles:
                keysNecesarias.append(clave[0])
                keysDisponibles = keysDisponibles + list(clave[1])
                chestsNuevo.remove(clave)
                nuevas = True
    
    if len(chestsNuevo) > 0:
        return False

    #print 'necesarias',sorted(keysNecesarias)
    #print 'disponibles',sorted(keysDisponibles)
    for key in keysNecesarias:
        if key in keysDisponibles:
            keysDisponibles.remove(key)
        else:
            return False

    return True
    
def processData(fileName):
    f = open(fileName)
    T = int(f.readline().strip())

    for i in xrange(1, T+1):
        #print 'INICIANDO'
        K,N = [int(val) for val in f.readline().strip().split(' ')]

        keys = [int(val) for val in f.readline().strip().split(' ')]

        chests = {}
        chestsNum = []
        for j in xrange(N):
            chestLine = [int(val) for val in f.readline().strip().split(' ')]
            Tj,Kj = chestLine[:2]
            chestKeys = chestLine[2:]

            chests[j] = [Tj,chestKeys]

        #print 'keys',sorted(keys)
        #print 'chests',chests
        
        stack = []
        fin = not posible(keys,chests)
        deadEnd = {}
        inicio = 0

        while not fin:
            #print 'stack',stack
            #print 'keys',sorted(keys)

            siguiente = -1
            #if i > 23:
                #print 'inicio',inicio
            if posible(keys,chests):
                for h in xrange(inicio, N):
                #print 'Comprobando',h,chests[h]
                    chest = chests[h]
                    if (chest[0] in keys):
                        #if i > 23:
                            #print 'ADD', h,chest,sorted(keys)
                        keys.remove(chest[0])
                        keys = keys + list(chest[1])
                        #print 'ADD', sorted(keys)
                        stack.append([h,chest])
                        chests[h] = [-1,[]]
                        siguiente = h
                        inicio = 0
                        break

            if siguiente == -1:
                #print 'NO SE HA ENCONTRADO'

                if stack and (len(stack) < len(chests)):
                    lastVal = stack.pop()
                    #if i > 23:
                        #print 'eliminando',lastVal,sorted(keys)
                    #print 'keys pre pop',sorted(keys)
                    keyUsed = lastVal[1][0]
                    keysFind = lastVal[1][1]
                    #print 'keys to remove', keysFind
                    chests[lastVal[0]] = lastVal[1]
                    inicio = lastVal[0] + 1 
                    keys.append(keyUsed)
                    for key in keysFind:
                        keys.remove(key)
                    deadEnd[lastVal[0]] = keys
                    #print 'eliminando keys post pop', sorted(keys)
                else:
                    fin = True


        resultado = 'Case #' + str(i) + ': '
        if stack:
            recorrido = [str(val[0] + 1) for val in stack]
            resultado = resultado + ' '.join(recorrido)

        else:
            resultado = resultado + 'IMPOSSIBLE'

        print resultado
        
        
    
    
    f.close()


#processData('prueba.in')
processData('D-large.in')
