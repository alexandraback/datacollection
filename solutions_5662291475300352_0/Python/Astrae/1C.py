# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""


            
        



import numpy as np

def main(ifn='C-small-1-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
                  
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                
                # on commence par lire le nombre de tribus
                i=int(inf.readline().strip())    # convertit en liste une ligne en virant les espaces
                
                L1=[0]*i
                L2=[0]*i
                L3=[0]*i
                for k in range(i): 
                    a=inf.readline().strip().split(' ')
                    L1[k]=int(a[0])
                    L2[k]=int(a[1])
                    L3[k]=int(a[2])
                        
                print L1
                print L2
                print L3
                
                # nbr de marcheurs
                
                N=sum(L2)
                print N
                
                goal=[] # on va mettre en combien de temps chaque marcheur termine 1 marche
                
                for k in range(len(L1)): # pour chaque groupe de marcheur
                    pos=L1[k]
                    for j in range(L2[k]): # pour chaque marcheur
                        v=float(360)/(L3[k]+j) # vitesse du j-ieme marcheur du groupe
                        goal=goal+[(360.-L1[k])/v]
                print goal
                
                # ensuite pour chaque marcheur, il faudrait savoir combien de tour il fait en un temps t
                
                nbrtour=[] # on va mettre en combien de temps chaque marcheur termine 1 marche
                
                t=max(goal) # temps minimal
                for k in range(len(L1)): # pour chaque groupe de marcheur
                    pos=L1[k]
                    for j in range(L2[k]): # pour chaque marcheur
                        v=float(360)/(L3[k]+j) # vitesse du j-ieme marcheur du groupe
                        nbrtour=nbrtour+[int(floor(((v*t+L1[k]))/360))]
                print nbrtour                
                
                resultat=0
                if N==1: # si un seul marcheur
                    resultat=0
                elif N==2:
                    if max(nbrtour)>1:
                        resultat=1



                    
                ouf.write("%d\n" %resultat)   # recopie le nombre puis saute une ligne                    


       


