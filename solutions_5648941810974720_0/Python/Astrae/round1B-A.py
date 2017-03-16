# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""



def qualifA(S):
    # on va compter dans la chaine de caractère le nbr de Z, de W, de R, de F, de X, de G...
    L=[0,0,0,0,0,0,0,0,0,0]
    for carac in S:
        if carac=='Z':
            L[0]+=1
        
        elif carac=='W':
            L[2]+=1
        elif carac=='X':
            L[6]+=1
        elif carac=='G':
            L[8]+=1
        elif carac=='H':
            L[3]+=1 ## attention, il faudra enlever le nbr de 8  !
        elif carac=='U':
            L[4]+=1
        elif carac=='F':
            L[5]+=1 ## attention, il faudra enlever le nombre de 4
        elif carac=='S':
            L[7]+=1  ## attention, il faudra enleverf le nombre de 6
        elif carac=='I':
            L[9]+=1 ## attention, il faudra enlever le nbr de 8, de 6 et de 5
        elif carac=='O':
            L[1]+=1 ## attention, il faudra enlever le nbr de 0 et de 2
            
    L[3]=L[3]-L[8]
    L[5]=L[5]-L[4]
    L[7]=L[7]-L[6]
    L[9]=L[9]-L[8]-L[6]-L[5]
    L[1]=L[1]-L[0]-L[2]-L[4]
    
    return L
            
    

            
                
                



import numpy as np

def main(ifn='A-small-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas

                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                L=inf.readline().strip().split(' ')
                print L
                resultat=qualifA(L[0])
                mot=''
                for j in range(10):
                    mot=mot+str(j)*resultat[j]

                        

                    
                if type(mot)==str:    
                    ouf.write("%s\n" %mot)   # recopie le nombre puis saute une ligne                    
                else:
                    ouf.write("%d\n" %resultat)                 


       


