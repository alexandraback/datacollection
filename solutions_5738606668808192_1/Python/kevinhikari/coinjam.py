def convertbase(angka, base):
	tmp3 = 0
	ii = 0
	while (angka > 0):
		if (angka % 2 == 1):
			tmp3 = tmp3 + 1 * base**ii
		angka = angka // 2
		ii += 1
	return tmp3

def cekprima(angka):
	if (angka % 2 == 0):
		return 2
	for i in range(3, 10000, 2):
		if (angka % i == 0):
			return i
	return -1

n = 31
hasil = []
f = open('out.out', 'w')
cnt = 0
print('Case #1:')
for i in range(0,2**n):
	if (cnt == 500):
		break
	tmp = i*2 + 2**n + 1
	tmplist = [convertbase(tmp,10)]
	salah = False
	for j in range(2,11):
		tmp2 = convertbase(tmp, j)
		tmp3 = cekprima(tmp2)
		if (tmp3 != -1):
			tmplist.append(tmp3)
		else:
			salah = True
			break
	if (salah == False):
		cnt += 1
		for j in range(0, len(tmplist)):
			if (j > 0):
				print(' ',end="")
				#f.write(' ')
			print(tmplist[j],end="")
			#f.write(str(tmplist[j]))
		print('')
		#f.write('\n')
#f.close()