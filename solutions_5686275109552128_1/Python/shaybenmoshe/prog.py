# For each diner, we have Pi and Ki (number of splits).
# Let Ri = ceil(Pi / Ki) = (Pi + Ki - 1) / Ki.
# We want to minimize max(Ri)+sum(Ki-1).

class Solver:
	
	def __init__(self, D, P):
		self.D = D
		self.RLevel = max(P)
		
		self.R = []
		for i in xrange(0, self.RLevel + 1):
			self.R.append([])
		
		for i in xrange(0, len(P)):
			di = [P[i], 1]
			self.R[di[0]].append(di)
	
	def solve(self):
		L = self.eval()
		
		while self.nextLevel():
			L = min(L, self.eval())
		
		return L
	
	def eval(self):
		M = 0
		S = 0
		for i in xrange(0, self.RLevel + 1):
			if len(self.R[i]) > 0:
				M = i
			
			for j in xrange(0, len(self.R[i])):
				S += self.R[i][j][1] - 1
		
		return S + M
	
	def nextLevel(self):
		if self.RLevel == 0:
			return False
		
		for i in xrange(0, len(self.R[self.RLevel])):
			di = self.R[self.RLevel][i]
			di[1] += 1
			Ri = (di[0] + di[1] - 1) / di[1]
			if Ri == self.RLevel:
				return False
			self.R[Ri].append(di)
		
		self.RLevel -= 1
		
		return True

fin = open("input.txt", "r")
fout = open("output.txt", "w")

T = int(fin.readline())
for c in xrange(1, T + 1):
	print "Solving case #" + str(c)
	
	D = int(fin.readline())
	P = [int(u) for u in fin.readline().split()]
	
	sol = Solver(D, P)
	
	fout.write("Case #" + str(c) + ": " + str(sol.solve()) + "\n")
