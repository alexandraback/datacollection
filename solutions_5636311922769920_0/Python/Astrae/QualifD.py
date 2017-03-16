# -*- coding: utf-8 -*-
"""
Created on Sat Apr 09 05:16:47 2016

@author: Fred
"""

# pour convertir une chaine de caractère en base K
def convert(n,K):
    res=0
    i=0
    for elt in n:
        res=res+int(elt)*(K**i)
        i=i+1
    return res
    
    
    

def qualifD(K,C,S):
    # Au niveau C, on peut tester C positions de départ d'un coup
    # On a K positions de départ pour le Gold au départ
    # donc on a besoin d'au moins K/C+1 étudiants
    if K==1:
        return '1'
    
    else:
        
    
        if K%C==0:
            if S<K/C:
                return 'IMPOSSIBLE'
        else:
            if S<K/C+1:
                return 'IMPOSSIBLE'


        L=[]
        n=[]
        
        for l in range(0,K):
            n=n+[l]
            if (l%C==C-1) or (l==K-1):
                L=L+[convert(n,K)+1]
                n=[]
                

    
        mot=str(L[0])
        for j in range(1,len(L)):
            mot=mot+' '+str(L[j])            
    
        return mot
        
    
    

        
                
                

            
                
                



import numpy as np

def main(ifn='D-small-attempt2.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
                
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                L=inf.readline().strip().split(' ')
                K=int(L[0])
                C=int(L[1])
                S=int(L[2])

                resultat=qualifD(K,C,S)
                               
   
                ouf.write("%s\n" %resultat)   # recopie le nombre puis saute une ligne                    
              


       


