#!/usr/bin/env python

NOMBRE_ARCHIVO_DE_ENTRADA = "a.in"
NOMBRE_ARCHIVO_DE_SALIDA = "outcome.out"

def imprime(case, texto):
	"""Recibe numero de case y texto que puede ser numero.
	Graba en salida."""
	#print "Case #"+str(case)+": "+str(texto)
	salida.write("Case #"+str(case)+": "+str(texto)+"\n")

def costoPorFilaNormal(columnas, largoBarco):
	return columnas / largoBarco

class Fila(object):
	def __init__(self, columnas, largoBarco):
		self.columnas = columnas
		self.largoBarco = largoBarco
		
		self.posicionBarco = 0
		
		self.disparos = []
		self.cantidadDeDisparos = 0
		self.golpesEn = []
		self.cantidadDeGolpes = 0
		
		for x in xrange(columnas):
			self.disparos.append(False)
			self.golpesEn.append(False)
			
	def disparoA(self, posicion):
		""" Devuelve True si le pego al barco. """
		if self.disparos[posicion]: return False
		self.disparos[posicion] = True
		self.cantidadDeDisparos += 1
		if posicion >= self.posicionBarco and posicion < self.posicionBarco+self.largoBarco:
			sePudoAcomodar = self.acomodarBarco(posicion)
			if sePudoAcomodar: return False
			self.golpesEn[posicion] = True
			self.cantidadDeGolpes += 1
			return True
		return False
	
	def acomodarBarco(self, posicion):
		lePegoAlBarco = False
		for posicionInicial in xrange(self.columnas-self.largoBarco+1):
			for y in xrange(self.largoBarco):
				if self.disparos[posicionInicial+y]: 
					lePegoAlBarco = True
					break
			if not lePegoAlBarco:
				estamosMintiendo = False
				for z in xrange(self.columnas):
					if z >= posicionInicial and z < posicionInicial+self.largoBarco: continue
					if self.golpesEn[z]:
						estamosMintiendo = True
					if not estamosMintiendo:
						self.posicionBarco = posicionInicial
						return True
			lePegoAlBarco = False
		
		return False
		
	def seHundioElBarco(self):
		return self.cantidadDeGolpes == self.largoBarco
		
		
def resuelve(filas, columnas, largoBarco):
	costoTotal = 0
	
	costoFilaNormal = costoPorFilaNormal(columnas, largoBarco)
	costoTotal += costoFilaNormal * (filas-1)
	
	fila = Fila(columnas, largoBarco)
	
	aDisparar = largoBarco - 1
	lePegue = fila.disparoA(aDisparar)
	primerGolpe = False
	primerGolpeEn = -1
	if lePegue:
		primerGolpe = True
		primerGolpeEn = aDisparar
		
	while not fila.seHundioElBarco():
		if primerGolpe:
			if aDisparar+1 < columnas:
				aDisparar += 1
				lePegue = fila.disparoA(aDisparar)
				if lePegue: continue
			
			costoTotal += largoBarco - fila.cantidadDeGolpes
			break
			
		aDisparar += largoBarco
		if aDisparar >= columnas:
			aDisparar -= largoBarco
			aDisparar += 1
		lePegue = fila.disparoA(aDisparar)
		if lePegue:
			primerGolpe = True
			primerGolpeEn = aDisparar
	
	costoTotal += fila.cantidadDeDisparos
	
	return costoTotal
	
def lector():
	entrada = open(NOMBRE_ARCHIVO_DE_ENTRADA, 'r')
	
	for caso in xrange(int(entrada.readline())):
		filas, columnas, largoBarco = entrada.readline().split()
		filas, columnas, largoBarco = int(filas), int(columnas), int(largoBarco) 
		sol = resuelve(filas, columnas, largoBarco)
		imprime(caso+1, sol)


def main():
	lector()

salida = open(NOMBRE_ARCHIVO_DE_SALIDA, 'w')
main()
salida.close()
