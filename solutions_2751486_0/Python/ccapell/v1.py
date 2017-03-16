'''
Created on 04/05/2013

@author: Carles
'''

def trataCaso(inFile):
    
    linea = inFile.readline()
    nombre = linea.partition(' ')[0]
    n = int(linea.partition(' ')[2])
    contador = 0

    longNombre = len(nombre)
    
    #print nombre, n
    for i in range(n, longNombre+1):
        for j in range(longNombre-i+1):
            if tieneCons(nombre[j:j+i],n):
                contador +=1
                #print "\n\n"
                    
    return contador

def tieneCons (nom, num):
    
    vocales = ('a','e','i','o','u')
    voca = 0
    cons = False
    contCons = 0
    max = 0
    
    #print nom
    for i in range(len(nom)):
        #print nom[i]
        if nom[i] in vocales:
            cons = False
            if max < contCons:
                max = contCons
            contCons = 0
        else:
            cons = True
            contCons +=1
            
    if max < contCons:
        max = contCons
    
    #print "contador:" + str(max)
    if max >= num:
        #print "Si"
        return True
    else:
        #print "NO"
        return False
        
    
    
def main():
    inFile = open('input.in', 'r')
    outFile = open('output.out', 'w')


    numCasos = int(inFile.readline())
    

    for i in range(numCasos):
        outFile.write("Case #"+str(i+1)+": "+str(trataCaso(inFile))+"\n")
        #print trataCaso(inFile)
        
    inFile.close()
    outFile.close()
        
if __name__ == "__main__":main()