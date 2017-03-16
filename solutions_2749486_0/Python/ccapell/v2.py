'''
Created on 12/05/2013

@author: Carles
'''


def trataCaso(inFile):
    
    linea = inFile.readline()
    xFinal = int(linea.partition(' ')[0])
    yFinal = int(linea.partition(' ')[2])
    camino = ''
    
    salto = 1
    
    x=0
    y=0

    print xFinal, yFinal
    
    while abs(xFinal - x) > salto:
        if xFinal > x:
            camino += 'E'
            x += salto
            salto +=1
        if xFinal < x:
            camino += 'W'
            x -= salto
            salto += 1
        #print camino, salto
        
    if xFinal > x:
        camino += 'WE' * (xFinal-x)
        salto += 2 * (xFinal-x)
        x += (xFinal-x)
        
    if x > xFinal:
        camino += 'EW' * (x-xFinal)
        salto += 2 * (x-xFinal)
        x -= (x-xFinal)
        
    while abs(yFinal - y) > salto:
        if yFinal > y:
            camino += 'N'
            y += salto
            salto +=1
        if yFinal < y:
            camino += 'S'
            y -= salto
            salto += 1
        #print camino, salto
        
    if yFinal > y:
        camino += 'SN' * (yFinal-y)
        salto += 2*(yFinal-y)
        y += (yFinal-y)
    if y > yFinal:
        camino += 'NS' * (y-yFinal)
        salto += 2*(y-yFinal)
        y -= (y-yFinal)
        
    return camino

    #===========================================================================
    # for i in range(500):
    #     camino = salta(xFinal,yFinal,i)
    #     if camino!= 'X':
    #         return camino
    #     
    #===========================================================================
    #return contador
    
def salta(x,y,distancia):
    if distancia > 0:
        for d in disponibles(x,y,distancia):
            if d.x == 0 and d.y==0 and distancia == 1:
                return d.direccion
            else: 
                dir = salta(d.x,d.y,distancia-1)
                if dir != 'X':
                    return dir + d.direccion
                else:
                    continue
    return 'X'
            
    
def disponibles(x,y,distancia):
    
    destino = [None]*4
    destino[0] = punto(x+distancia,y,'W')
    destino [1] = punto(x-distancia,y,'E')
    destino[2] = punto(x,y+distancia,'S')
    destino[3] = punto(x,y-distancia,'N')
    
    return destino


class punto:
    def __init__(self,x,y,direccion):
        self.x = x
        self.y = y
        self.direccion = direccion
    


def main():
    inFile = open('input.in', 'r')
    outFile = open('output.out', 'w')
    
    
    numCasos = int(inFile.readline())
    

    for i in range(numCasos):
        outFile.write("Case #"+str(i+1)+": "+trataCaso(inFile)+"\n")
        #print trataCaso(inFile)
        
    inFile.close()
    outFile.close()
        
if __name__ == "__main__":main()
