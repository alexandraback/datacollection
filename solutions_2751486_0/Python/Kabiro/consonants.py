#!/usr/bin/python
# -*- coding: utf-8 -*-

from math import *
from decimal import Decimal

inputFile = open("A-small-attempt0.in","r")
solution = open("A-small-attempt0.out","w")

T = int(inputFile.readline().split("\n")[0])

voyelles = ["a","e","i","o","u"]

def hasNConsecutivesConsons(substring, n):
	consonnesConsecutives = 0
	for c in substring:
		if c not in voyelles:
			consonnesConsecutives += 1
		else :
			consonnesConsecutives = 0
		if consonnesConsecutives == n:
			return True
	return False

for i in range(T):
	ligne = inputFile.readline()
	name = ligne.split(" ")[0]
	n = int(ligne.split(" ")[1].split("\n")[0])

	reponse = 0
	for indice in range(len(name) + 1):
		for indice_bis in range(n + indice, len(name) + 1):
			sub = name[indice : indice_bis]
			if hasNConsecutivesConsons(sub,n):
				reponse += 1
			#print sub,reponse
			
	print "////////////////////"


	solution.write("Case #"+str(i+1)+": "+str(reponse)+"\n")
	print name,reponse