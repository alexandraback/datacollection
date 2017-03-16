# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""


def main(ifn='A-small-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                

                liste = inf.readline().strip().split(' ')    # convertit en liste une ligne en virant les espaces
                                                             # quand on utilise readline, passe à la ligne suivante.
                
                
                
                taille=int(liste[0])  #shyness max
                
                solution=0  # nbr de spectateurs à inviter
                shyness=0   # niveau de timidité actuel de la salle
                for k in range(taille+1):  # on parcourt chaque rang petit à petit
                    if k>=shyness:
                        # dans ce cas, la shyness n'est pas assez élevée et on est au niveau shyness. On doit donc rajouter
                        # des gens jusqu'à atteindre ce qu'il faut pour faire lever les spectateur de ce niveau
                        # autrement dit, il faut en rajouter 
                        nbr=k-shyness
                        solution=solution+nbr
                        shyness=k+int(liste[1][k])                        
                    
                    else:
                        shyness=shyness+int(liste[1][k]) # on fait lever les gens, on ne doit rajouter personne
       
                ouf.write("%d\n" %solution)   # recopie le nombre puis saute une ligne

