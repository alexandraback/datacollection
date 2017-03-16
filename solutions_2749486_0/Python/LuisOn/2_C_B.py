# -*- coding: utf-8 -*-
## Problema 2_C_A
#import itertools
#import math
#import time

input = open('C:\Users\Luis\Desktop\CODE JAM\B-small-attempt1.in', 'r')

output = open('C:\Users\Luis\Desktop\CODE JAM\output_2_C_B_small.txt', 'w')

casos=int(input.readline())
#print casos


for ic in range(casos):#Volver a poner "casos"
    
    #LEO DATOS
    linea1=input.readline().split()
    xfin=int(linea1[0])
    yfin=int(linea1[1])
   
    fin=0
    xnow=0
    ynow=0
    salto=1
    letras={1:'E',-1:'W',2:'N',-2:'S'}
    resultado=''

    #EMPIEZO RESOLUCION
    while fin==0:
        #time.sleep(0.1)
        ex=xfin-xnow
        ey=yfin-ynow
        if abs(ex)>ex:
            sx=-1
        else:
            sx=1
        if abs(ey)>ey:
            sy=-1
        else:
            sy=1
        
        if (abs(ex)<abs(ey) and abs(ex)>0) or abs(ey)==0:
        
            if abs(ex)>=salto:
                xnow+=sx*salto
                #resultado.append(letras[sx])
                resultado+=letras[sx]
                salto+=1
            else:
                xnow+=-sx*salto
                resultado+=letras[-sx]
                salto+=1
                xnow+=sx*salto
                resultado+=letras[sx]
                salto+=1
        else:
            if abs(ey)>=salto:
                ynow+=sy*salto
                resultado+=letras[sy*2]
                salto+=1
            else:
                ynow+=-sy*salto
                resultado+=letras[-sy*2]
                salto+=1
                ynow+=sy*salto
                resultado+=letras[sy*2]
                salto+=1
        
        if xnow==xfin and ynow==yfin:
            fin=1
        #print xnow,ynow
    
    if len(resultado)>500:
        print 'MAS de 500'  
    else:
        print resultado               
    
      
                        
        
                
    
          
 
        
            
    output.write('Case #{0}: {1}\n'.format(ic+1,resultado))
print "FIN"


       

input.close()
output.close()
