# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""





def main(ifn='B-large.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas
            
                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                

                nbrassiette= int(inf.readline().strip())
                repartition= inf.readline().strip().split(' ')
                
                # on convertit repartition en entiers
                liste=[]
                for k in range(len(repartition)):
                    liste=liste+[int(repartition[k])]
                
                print liste


                tempsmax=max(liste)
                
                if tempsmax==1:
                    tempstotal=1
                elif tempsmax==2:
                    tempstotal=2
                elif tempsmax==3:
                    tempstotal=3
                else:
                    listetemps=[]
                    for b in range(2,tempsmax+1): # on va faire les divisions euclidiennes par b, on suppose qu'on mange exactement b fois
                                            # à la fin
                        tempsb=0
                        for k in liste:
                            if k>b: # sinon k est plus petit que b et on ne le décompose pas
                                if k%b==0:
                                    tempsb=tempsb+k/b-1
                                else:
                                    tempsb=tempsb+k/b
                            
                        listetemps=listetemps+[tempsb+b]
                        
                    tempstotal=min(listetemps)
                ouf.write("%d\n" %tempstotal)   # recopie le nombre puis saute une ligne

