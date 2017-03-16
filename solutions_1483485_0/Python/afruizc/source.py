
from string import maketrans

entrada = file('small.in')
salida = file('small.out', 'w')

casos = int(entrada.readline())

ingles = "abcdefghijklmnopqrstuvwxyz "
google = "ynficwlbkuomxsevzpdrjgthaq "

transt = maketrans(google, ingles)

for i in range(1, casos+1):
	linea = entrada.readline()
	salida.write("Case #%d: %s" % (i, linea.translate(transt)))

entrada.close()
salida.close()
