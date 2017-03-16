# -*- coding: utf-8 -*-
"""
Created on Sat Apr 09 05:16:47 2016

@author: Fred
"""



def qualifB(L):
    # On va tenter cette strat :
        # si ya que des + : fini
        # sinon :
            #si la liste commence par un -, on parcourt la liste jusqu'au dernier - et on
            #flip jusque là (comme ça on a mis des + à la fin)
            
            #si la liste commence par un +, on flip les premiers + jusqu'à tomber sur un -
    
    k=len(L)-1
    exit1=True
    while exit1 and k>0:
        if L[k]=='+':
            k=k-1
        else:
            exit1=False
    # donc en sortie, on peut tout retirer de la fin jusqu'à k
    L=L[:k+1]

    
    
    if len(L)==0: # on commence par une liste avec que des +
        return 0
    elif L=='-': # on enlève la liste de longueur 1 qui contient juste un '-' en tête
        return 1    
    else:
        n=0 # compteur de flip
        while True:
            
            
            signe=L[0]
            
            if signe=='+':
                k=1
                exit=True
                while exit and k<len(L):
                    if L[k]=='-':
                        exit=False
                    else:
                        k=k+1
                
                if exit:   # dans ce cas, on a que des + dans la liste
                    return n
                else:           # dans ce cas, on a trouvé un -, on flippe jusqu'à l'indice k
                    L=k*'-'+L[k:]
                    n=n+1
            else:  # dans ce cas, la liste commence par un -
                    # on ne garde alors que ce qui est entre le - et la fin car par de + à la fin
                    
                k=0
                while k<len(L) and L[k]=='-':
                    k=k+1
                
                if k==len(L): # autrement dit on a que des - dans la liste
                    return n+1 # car on flip une fois et c'est fini
                else:
                    n=n+1
                    L=L[k:] # on efface les - en augmentant le compteur
                    L=L[::-1] # on flip
                    newword=''
                    for j in L:
                        if j=='-':
                            newword=newword+'+'
                        else:
                            newword=newword+'-'
                    L=newword
                
                

            
                
                



import numpy as np

def main(ifn='B-small-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
                
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                L=inf.readline().strip().split(' ')[0]
                
                resultat=qualifB(L)

                    
                ouf.write("%d\n" %resultat)                 


       


