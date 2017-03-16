# !/usr/bin/python
# -*- coding: utf-8 -*-

import re
entree=open("input.txt","r")
entree=open("A-large.in","r")
ligne=entree.readline()
solution=open("solution.out","w")
boucles=re.findall(r'\d+\b',ligne)
inc=1
for b in range(int(boucles[0])):
	ligne=entree.readline()
	nombres=re.findall(r'\d+\b',ligne)
	ligne=entree.readline()
	probas=re.findall(r'\d+[\.\d+]*\b',ligne)
	proba_bon=[]
	proba_bon.append(float(probas[0]))
	for i in range(1,len(probas)):
		proba_bon.append(proba_bon[i-1]*float(probas[i]))
	esperance_continuer=float(proba_bon[max(int(nombres[0])-1,0)])*(1.0+float(nombres[1])-float(nombres[0]))
	esperance_continuer+=(1.0-float(proba_bon[max(int(nombres[0])-1,0)]))*(1.0+float(nombres[1])+1.0+float(nombres[1])-float(nombres[0]))
	esperance_entree=2.0+float(nombres[1])
	esperance_suppression=[]
	esperance_suppression.append(999999999.99)
	for i in range(1,1+int(nombres[0])):
		nbre_touches_bon=1+2*i+int(nombres[1])-int(nombres[0])
		indice=int(nombres[0])-i-1
		proba_correct=0
		if indice>-1:
			proba_correct=proba_bon[indice]
		else:
			proba_correct=1.0
		nbre_touches_faux=nbre_touches_bon+int(nombres[1])+1
		esperance_suppression.append(proba_correct*nbre_touches_bon+(1.0-proba_correct)*nbre_touches_faux)
	mini=min(esperance_suppression)
	mini=min(mini,esperance_continuer,esperance_entree)
	
	compteur=0
	apres_virgule=False
	for x in str(mini):
		if apres_virgule==True:
			compteur+=1
		if x==".":
			apres_virgule=True
	mini=str(mini)
	compteur=min(compteur,6)
	for i in range(compteur,6):
		mini+="0"
	
	solution.write("Case #"+str(inc)+": "+mini+"\n")
	inc+=1
