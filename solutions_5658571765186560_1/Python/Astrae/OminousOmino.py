# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""





def main(ifn='D-large.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                

                L= inf.readline().strip().split()
                X=int(L[0])
                R=int(L[1])
                C=int(L[2])
                
                if X>6:
                    winner='RICHARD'
                else:
                    if X==1: # histoire d'éviter les cas débiles
                        winner='GABRIEL'
                    else:                        
                        if R*C%X!=0:
                            winner='RICHARD'
                        else: # on a donc X entre 2 et 6 et X qui divise R*C
                            if X>max(R,C): # on prend la piece de tetris toute droite
                                winner='RICHARD'
                            else:
                                if min(R,C)<(X+1)/2: # on prend un X en "L"
                                    winner='RICHARD'
                                else:                                        
                                    if X==2:
                                        winner='GABRIEL'
                                    elif X==3:
                                        winner='GABRIEL'
                                    elif X==4:
                                        if min(R,C)==2:
                                            winner='RICHARD'
                                        else:
                                            winner='GABRIEL'
                                    elif X==5:
                                        if min(R,C)==3:
                                            if max(R,C)==5:
                                                winner='RICHARD'
                                            else:
                                                winner='GABRIEL'
                                        else:
                                            winner='GABRIEL'
                                    elif X==6:
                                        if min(R,C)==3:
                                            winner='RICHARD'
                                        else:
                                            winner='GABRIEL'
                                            
                                            
                                        

                                        
                ouf.write(winner+'\n')   # recopie le vainqueur puis saute une ligne

