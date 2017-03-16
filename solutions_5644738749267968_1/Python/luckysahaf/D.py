
def war(A,B):
	score = 0
	while len(A) > 0:
		a = A[len(A)-1]
		to_remove = -1
		for i in range(0,len(B)):
			if B[i] > a:
				to_remove = B[i]
				break
		if to_remove > 0:
			B.remove(to_remove)
			A.remove(a)
		else:
			B.remove(B[0])
			A.remove(a)
			score += 1
	return score
#end-of-function

def deceitful_war(A,B):
	score = 0
	while len(A) > 0:	
		a = A[len(A)-1]
		if a > B[len(B)-1]:
			A.remove(a)
			B.remove(B[len(B)-1])
			score += 1
		else:
			A.remove(A[0])
			B.remove(B[len(B)-1])
	return score
#end-of-function

def solve(A,B):
	A = sorted(A)
	a = list(A)
	B = sorted(B)
	b = list(B)
	score_war = war(A,B)
	score_deceitful_war = deceitful_war(a,b)
	return [score_deceitful_war,score_war]
#end-of-function

if __name__ == '__main__':
	T = int(raw_input())
	for i in range(0,T):
		N = int(raw_input())
		Naomi = raw_input()
		Ken = raw_input()
		Naomi = Naomi.split(' ')
		Ken = Ken.split(' ')
		for j in range(0,N):
			Naomi[j] = (int(Naomi[j][2:]))*100000
			Ken[j] = (int(Ken[j][2:]))*100000
		score = solve(Naomi,Ken)
		print "Case #%i: %i %i" %(i+1,score[0],score[1])

