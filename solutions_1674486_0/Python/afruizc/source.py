entrada = open('small.in', 'r')
salida = open('small.out', 'w')

def hayCamino(caminos, origen, destino):
	if destino in caminos[origen]:
		return True
	else:
		for i in caminos[origen]:
			if hayCamino(caminos, i, destino):
				return True
		return False


def numCaminos(caminos, origen, destino):
	num = 0
	if destino in caminos[origen]:
		num += 1
	for j in caminos[origen]:
		if hayCamino(caminos, j, destino):
			num += 1
	return num


T = int(entrada.readline())

for i in range(T):
	caminos = {}
	N = int(entrada.readline())
	for j in range(1, N+1):
		temp = map(int, entrada.readline().split())
		M = temp[1:]
		caminos[j] = M
	x = 1
	listo = False
	while x <= len(caminos) and not listo:
		y = 1
		while y <= len(caminos) and not listo:
			if hayCamino(caminos, x, y):
				n = numCaminos(caminos, x, y)
				if n >= 2:
					salida.write('Case #%d: Yes\n' % (i+1))
					listo = True
			y += 1
		x += 1
	if not listo:
		salida.write('Case #%d: No\n' % (i+1))

