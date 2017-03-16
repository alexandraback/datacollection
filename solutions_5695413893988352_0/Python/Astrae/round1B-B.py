# -*- coding: utf-8 -*-
"""
Created on Sat Apr 09 05:16:47 2016

@author: Fred
"""



def qualifB(L1,L2):
    
    if L1=='?' and L2=='?':
        return ['0','0']
    
    if len(L1)==1 and L1!='?' and L2!='?':
        return [L1,L2]
    # ok donc on récupère les 2 chaines. On stocke dans une liste
    # les différents scores avec la strat suivante :
        
        # si on trouve une lettre différente au début alors pas le choix, le plus petit on complète
        #avec des 9 et le grand avec des 0
        
        # si on a des lettres identiques, et qu'on rencontre un ? alors on a 2 choix :
            
            # si en face ya un nbr, on teste avec i, i-1 et i+1 et on complète avec l'algo précédent
            
            # si en face on a un ?, on teste avec 0,0 ou 0,1 ou 1,0 et on complète la fin avec l'algo précédent
    # on récupère les deux scores        

    if L1[0]!='?' and L2[0]!='?':
        if int(L1[0])<int(L2[0]):
            return [L1.replace('?','9'),L2.replace('?','0')]

        elif int(L1[0])>int(L2[0]):
            return [L1.replace('?','0'), L2.replace('?','9')]

        else: # même première lettre
            score=qualifB(L1[1:],L2[1:])
            
            return [L1[0]+score[0],L1[0]+score[1]]
            
    elif L1[0]=='?' and L2[0]!='?':
        if L1=='?':
            return [L2[0],L2[0]]
        
        if L2[0]=='0':
            score1=qualifB('0'+L1[1:],L2)
            score2=qualifB('1'+L1[1:],L2)
            
            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])):
                return score2
            else:
                return score1
        elif L2[0]=='9':
            score1=qualifB('8'+L1[1:],L2)
            score2=qualifB('9'+L1[1:],L2)
            
            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])):
                return score2
            else:
                return score1            
        else:
            n0=str(int(L2[0])-1)
            n1=str(int(L2[0]))            
            n2=str(int(L2[0])+1)
            
            score1=qualifB(n0+L1[1:],L2)
            score2=qualifB(n1+L1[1:],L2)
            score3=qualifB(n2+L1[1:],L2)
            
            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score3[0])-int(score3[1]))<abs(int(score1[0])-int(score1[1])) and abs(int(score3[0])-int(score3[1]))<abs(int(score2[0])-int(score2[1])):
                return score3
            else:
                if abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])):
                    return score2
                else:
                    return score1
            
    elif L1[0]!='?' and L2[0]=='?':
        if L2=='?':
            return [L1[0],L1[0]]
        
        
        
        
        # cette fois on change le score de L2. Alors là c'est vicieux car il
    # faudra prendre le score où L1 est le plus petit d'abord...
    
        if L1[0]=='0':
            score1=qualifB(L1,'0'+L2[1:])
            score2=qualifB(L1,'1'+L2[1:])
            
            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])):
                return score2
            elif abs(int(score2[0])-int(score2[1]))>abs(int(score1[0])-int(score1[1])):
                return score1
            else:
                if int(score1[0])<int(score2[0]):
                    return score1
                elif int(score1[0])>int(score2[0]):
                    return score2
                else:
                    return score1
                    
                    
                    
        elif L1[0]=='9':
            score1=qualifB(L1,'8'+L2[1:])
            score2=qualifB(L1,'9'+L2[1:])
            

            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])):
                return score2
            elif abs(int(score2[0])-int(score2[1]))>abs(int(score1[0])-int(score1[1])):
                return score1
            else:
                if int(score1[0])<int(score2[0]):
                    return score1
                elif int(score1[0])>int(score2[0]):
                    return score2
                else:
                    return score1
                    
                    
        else:
            n0=str(int(L1[0])-1)
            n1=str(int(L1[0]))            
            n2=str(int(L1[0])+1)
            
            score1=qualifB(L1,n0+L2[1:])
            score2=qualifB(L1,n1+L2[1:])
            score3=qualifB(L1,n2+L2[1:])
            
            # on veut renvoyer d'abord le score où l'équipe 1 est le plus bas
            
            if abs(int(score3[0])-int(score3[1]))<abs(int(score1[0])-int(score1[1])) and abs(int(score3[0])-int(score3[1]))<abs(int(score2[0])-int(score2[1])):
                return score3
            elif abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])) and abs(int(score2[0])-int(score2[1]))<abs(int(score3[0])-int(score3[1])):
                return score2    
            elif abs(int(score1[0])-int(score1[1]))<abs(int(score3[0])-int(score3[1])) and abs(int(score1[0])-int(score1[1]))<abs(int(score2[0])-int(score2[1])):
                return score2
            else:
                if abs(int(score3[0])-int(score3[1]))==abs(int(score1[0])-int(score1[1])) and abs(int(score3[0])-int(score3[1]))==abs(int(score2[0])-int(score2[1])):
                    # les trois scores égaux
                    
                    if int(score1[0])<int(score2[0]):
                        if int(score1[0])<int(score3[0]):
                            return score1
                        elif int(score1[0])>int(score3[0]):
                            return score3
                        else:
                            return score1
                    elif int(score2[0])<int(score1[0]):
                        if int(score2[0])<int(score3[0]):
                            return score2
                        elif int(score2[0])>int(score3[0]):
                            return score3
                        else:
                            return score2
                    else:
                        if int(score1[0])<int(score3[0]):
                            if int(score1[1])<int(score2[1]):
                                return score1
                            else:
                                return score2
                        if int(score1[0])==int(score3[0]):
                            if int(score1[1])<int(score2[1]) and int(score1[1])<int(score3[1]):
                                return score1
                            elif int(score2[1])<int(score3[1]):
                                return score2
                            else:
                                return score3
                else:
                    if abs(int(score3[0])-int(score3[1]))==abs(int(score1[0])-int(score1[1])):
                        if int(score1[0])<int(score3[0]):
                            return score1
                        elif int(score1[0])>int(score3[0]):
                            return score3
                        else:
                            if int(score1[1])<int(score3[1]):
                                return score1
                            else:
                                return score3
                    elif abs(int(score3[0])-int(score3[1]))==abs(int(score2[0])-int(score2[1])):
                        if int(score2[0])<int(score3[0]):
                            return score2
                        elif int(score2[0])>int(score3[0]):
                            return score3
                        else:
                            if int(score2[1])<int(score3[1]):
                                return score2
                            else:
                                return score3
                    elif abs(int(score1[0])-int(score1[1]))==abs(int(score2[0])-int(score2[1])):
                        if int(score2[0])<int(score1[0]):
                            return score2
                        elif int(score2[0])>int(score1[0]):
                            return score1
                        else:
                            if int(score2[1])<int(score1[1]):
                                return score2
                            else:
                                return score1                    
                    
                    
    else: # les 2 mots commencent par '?'
    
        score1=qualifB('0'+L1[1:],'0'+L2[1:])
        score2=qualifB('0'+L1[1:],'1'+L2[1:])
        score3=qualifB('1'+L1[1:],'0'+L2[1:])
        
        if abs(int(score3[0])-int(score3[1]))<abs(int(score1[0])-int(score1[1])) and abs(int(score3[0])-int(score3[1]))<abs(int(score2[0])-int(score2[1])):
            return score3
        elif abs(int(score2[0])-int(score2[1]))<abs(int(score1[0])-int(score1[1])) and abs(int(score2[0])-int(score2[1]))<abs(int(score3[0])-int(score3[1])):
            return score2    
        elif abs(int(score1[0])-int(score1[1]))<abs(int(score3[0])-int(score3[1])) and abs(int(score1[0])-int(score1[1]))<abs(int(score2[0])-int(score2[1])):
            return score1
        else:
            if abs(int(score3[0])-int(score3[1]))==abs(int(score2[0])-int(score2[1])) and abs(int(score3[0])-int(score3[1]))==abs(int(score1[0])-int(score1[1])):
                return score1
            elif abs(int(score3[0])-int(score3[1]))==abs(int(score2[0])-int(score2[1])):
                return score2
            elif abs(int(score3[0])-int(score3[1]))==abs(int(score1[0])-int(score1[1])):
                return score1
            elif abs(int(score2[0])-int(score2[1]))==abs(int(score1[0])-int(score1[1])):
                return score1
                    
                    
                

                

            
                
                



import numpy as np

def main(ifn='B-small-attempt1.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas

                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                L=inf.readline().strip().split(' ')
                print L
                resultat=qualifB(L[0],L[1])
                

                mot1=resultat[0]
                mot2=resultat[1]
                mot=mot1+' '+mot2

#


#
#                    
                ouf.write("%s\n" %mot)                 


       


