from fractions import Fraction
from math import floor, ceil, copysign, sqrt, atan2, degrees

sauts = ""

def propagation():
	return 1

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		nbOcc = 0
		H, W, D = [int(_) for _ in input().split()]
		grille = [input() for i in range(H)]
		for i, ligne in enumerate(grille):
			for j, case in enumerate(ligne):
				if case == "X":
					i0 = i
					j0 = j
		supergrille = []
		w = W - 2
		h = H - 2
		for i in range(2 * D + 1):
			supergrille.append(["."] * (2 * D + 1))
		j = D % (2 * w)
		while(j <= 2 * D):
			supergrille[D][j] = "X"
			j += 2 * w
		j = (D + 2 * (w - j0) + 1) % (2 * w)
		while(j <= 2 * D):
			supergrille[D][j] = "X"
			j += 2 * w
		supergrille = ["".join(ligne) for ligne in supergrille]
		i = D % (2 * h)
		while(i <= 2 * D):
			supergrille[i] = supergrille[D]
			i += 2 * h
		i = (D + 2 * (h - i0) + 1) % (2 * h)
		while(i <= 2 * D):
			supergrille[i] = supergrille[D]
			i += 2 * h
		fractions = []
		for i in range(-D, D + 1):
			for j in range(1, D + 1):
				if i * i + j * j <= D * D:
					fractions.append(Fraction(i, j))		
		fractions = list(set(fractions))
		for cote in [-1, 1]:
			for f in fractions:
				# print(f)
				it = f.numerator
				jt = cote * f.denominator
				while(D + it >= 0 and D + it <= 2 * D and D + jt >= 0 and D + jt <= 2 * D and supergrille[D + it][D + jt] == "."):
					it += f.numerator
					jt += cote * f.denominator
				if D + it >= 0 and D + it <= 2 * D and D + jt >= 0 and D + jt <= 2 * D and supergrille[D + it][D + jt] == "X" and it * it + jt * jt <= D * D:
					supergrille[D + it] = list(supergrille[D + it])
					supergrille[D + it][D + jt] = "O"
					supergrille[D + it] = "".join(supergrille[D + it])
					nbOcc += 1
		for i in range(D - 1, -1, -1):
			if supergrille[i][D] == "X":
				supergrille[i] = list(supergrille[i])
				supergrille[i][D] = "O"
				supergrille[i] = "".join(supergrille[i])
				nbOcc += 1
				break
		for i in range(D + 1, 2 * D + 1):
			if supergrille[i][D] == "X":
				supergrille[i] = list(supergrille[i])			
				supergrille[i][D] = "O"
				supergrille[i] = "".join(supergrille[i])
				nbOcc += 1
				break
		# for ligne in supergrille:
			# print(ligne)
		print("Case #{}: {}".format(t + 1, nbOcc))
