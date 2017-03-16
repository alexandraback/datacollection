# -*- coding: utf-8 -*-
## Problema 2_C_A
#import itertools

input = open('C:\Users\Luis\Desktop\CODE JAM\A-small-attempt0.in', 'r')

output = open('C:\Users\Luis\Desktop\CODE JAM\output_2_C_A_small.txt', 'w')

casos=int(input.readline())
#print casos


for ic in range(casos):#Volver a poner "casos"
    
    #LEO DATOS
    linea1=input.readline().split()
    nombre=linea1[0]
    n=int(linea1[1])
    tam=len(nombre)
   
    resultado=0
    suma=0
    #EMPIEZO RESOLUCION
    if tam<n:
        resultado=0
    else:
        for i in range(tam):
            if (tam-i)<n:
                pass
            else:
                suma=0
                for j in range(tam-i):
                    if nombre[i+j]!='a' and nombre[i+j]!='e' and nombre[i+j]!='i' and nombre[i+j]!='o' and nombre[i+j]!='u':
                        suma+=1
                    else:
                        suma=0
                                        
                    if suma>=n:
                        resultado+=tam-(i+j)
                        break
                
    print resultado                 
    
      
                        
        
                
    
          
 
        
            
    output.write('Case #{0}: {1}\n'.format(ic+1,resultado))
print "FIN"


       

input.close()
output.close()
