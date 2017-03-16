# -*- coding: utf-8 -*-
"""
Created on Sat Apr 09 05:16:47 2016

@author: Fred
"""



def qualifC(n):
    # On remarque que X**15+X**n0+X**n1+1 est toujours divisible par X+1 (-1 racine évidente)
    # si on choisit n0 et n1 impairs. On prend tous les couples et ça marche
    
    # On remarque la même chose pour X**31+X**n0+X**n1+1 pour le big
    
    # Donc le seul truc qui reste à faire est de renvoyer la liste X+1 pour
    # tous les nombres qu'on peut générer (2 parmi n donc)
    
    # la liste des diviseurs sera toujours la même en fait...
    

    
    
#    Ldiv='3 4 5 6 7 8 9 10 11'
    
    coin=[0]*n
    coin[0]=1
    coin[n-1]=1
    mot=''
    for elt in coin:
        mot=mot+str(elt)    
    resultat=[mot+' 3 4 5 6 7 8 9 10 11']    
    for k in range(1,n-2):
        for j in range(k+1,n-1,2):
            coin=[0]*n
            coin[0]=1
            coin[n-1]=1
            coin[k]=1
            coin[j]=1
            mot=''
            for elt in coin:
                mot=mot+str(elt)
            resultat=resultat+[mot+ ' 3 4 5 6 7 8 9 10 11']
            
    # ok donc avec ça on en a 49 et 225. Pour le small, je peux aussi prendre 10000...001 en fait
            
    # on va rajouter les pair+pair+impair+impair
    for k in range(1,n-2):
        for j in range(k+2,n-3,2):
            # avec ça on parcourt les indices pairs
            for i in range(2,n-2):
                for l in range(i+2,n-3,2):
                    # et là les impairs
                    coin=[0]*n
                    coin[0]=1
                    coin[n-1]=1
                    coin[k]=1
                    coin[j]=1
                    coin[i]=1
                    coin[l]=1
                    mot=''
                    for elt in coin:
                        mot=mot+str(elt)
                    resultat=resultat+[mot+ ' 3 4 5 6 7 8 9 10 11']
                    if len(resultat)==500:
                        return resultat
        
                
                

            
                
                



import numpy as np

def main(ifn='C-large.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
                
                ouf.write("Case #%d:\n" %(tnoc+1))   # case dans laquelle on écrit en sortie
                n=int(inf.readline().strip().split(' ')[0])
                print n
                resultat=qualifC(n)
                
                for mot in resultat:
                    
                    ouf.write("%s\n" %mot)                 


       


