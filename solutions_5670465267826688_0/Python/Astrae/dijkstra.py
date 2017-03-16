# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""

import numpy as np

# définition des matrices des quaternions

ID=np.array([[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]])
I=np.array([[0,-1,0,0],[1,0,0,0],[0,0,0,-1],[0,0,1,0]])
J=np.array([[0,0,-1,0],[0,0,0,1],[1,0,0,0],[0,-1,0,0]])
K=np.array([[0,0,0,-1],[0,0,-1,0],[0,1,0,0],[1,0,0,0]])


def caractoquater(car): #convertit un caractère en sa matrice
    if car=='i':
        return I
    elif car=='j':
        return J
    else:
        return K

def quatertocarac(A):
    if np.array_equal(A,I):
        return 'i'
    elif np.array_equal(A,J):
        return 'j'
    elif np.array_equal(A,K):
        return 'k'
    else:
        return 'N' # mauvais caractère


def main(ifn='C-small-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                

                L= inf.readline().strip().split()
                chaine= inf.readline().strip()*int(L[1])
                
                # dans chaine, on a TOUTE la chaine de caractères (ptet un peu violent pour le cas global...)
                #print L
                #print chaine
                
                # On va à présent lire la chaine à partir du début et faire des produits tant qu'on ne tombe pas sur I.
                
                solution='NO'
                n=len(chaine)
                if n >2: # chaine pas trop courte


                    car=chaine[0]
                    C=caractoquater(car)
                    indice=1 # indice dans le parcours de la chaine                    
                    while indice<n and not np.array_equal(C,I):
                        C=np.dot(C,caractoquater(chaine[indice])) # on fait le produit
                        indice=indice+1
                        
                    if indice<n:

                         # on a trouvé un i, on passe à l'indice suivant, il faut donc encore un peu de place !
                        car=chaine[indice]
                        C=caractoquater(car)
                        indice=indice+1
                        while not np.array_equal(C,J) and indice<n:

                            C=np.dot(C,caractoquater(chaine[indice])) # on fait le produit                        
                            indice=indice+1
                            
                        if indice<n:
    
                             # on a trouvé un j, on passe à l'indice suivant, il faut donc encore un peu de place !

                            car=chaine[indice]
                            C=caractoquater(car)
                            indice=indice+1
                            while indice<n: # il faut cette fois aller jusqu'au bout et trouver un k
                                C=np.dot(C,caractoquater(chaine[indice])) # on fait le produit
                                indice=indice+1                                
                            if np.array_equal(C,K):
                                solution='YES'
                
                print solution

                ouf.write(solution+'\n')   # recopie le nombre puis saute une ligne

