# !/usr/bin/python
# -*- coding: utf-8 -*-

import re
entree=open("input.txt","r")
ligne=entree.readline()
solution=open("solution.out","w")
boucles=re.findall(r'\d+\b',ligne)
inc=1

def update_niveaux(nb_niveaux,etoiles_niveau,niveau,etoiles,appris,compteur):
	for j in range(nb_niveaux):
		if niveau[j][1]==False:
			if etoiles_niveau[j][1]<=etoiles:
				if niveau[j][0]==False:
					etoiles+=2
				else:
					etoiles+=1
				niveau[j][0]=True
				niveau[j][1]=True
				appris=True
				compteur+=1
	for j in range(nb_niveaux):
		if appris==False and niveau[j][0]==False and etoiles_niveau[j][0]<=etoiles:
			etoiles+=1
			niveau[j][0]=True
			appris=True
			compteur+=1
	return (etoiles,appris,niveau,compteur)



for b in range(int(boucles[0])):
	ligne=entree.readline()
	nombres=re.findall(r'\d+\b',ligne)
	nb_niveaux=int(nombres[0])
	etoiles_niveau=[]
	niveau=[]
	for i in range(nb_niveaux):
		ligne=entree.readline()
		nombres=re.findall(r'\d+\b',ligne)
		entiers=[]
		for i in nombres:
			entiers.append(int(i))
		etoiles_niveau.append(entiers)
		niveau.append([False,False])
	appris=True
	compteur=0
	etoiles=0
	while appris==True:
		appris=False
		retour=update_niveaux(nb_niveaux,etoiles_niveau,niveau,etoiles,appris,compteur)
		etoiles=retour[0]
		appris=retour[1]
		niveau=retour[2]
		compteur=retour[3]
		'''print "etoiles : "+str(etoiles)
		print "compteur : "+str(compteur)
		for n in niveau:
			print n
		print " "
		a=input()'''
	resultat=str(compteur)
	for n in niveau:
		if n[1]==False:
			resultat="Too Bad"
	print "resultat "+str(inc)+" : "+resultat
	print "////////////////"
	solution.write("Case #"+str(inc)+": "+resultat+"\n")
	inc+=1
