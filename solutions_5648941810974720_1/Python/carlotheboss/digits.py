num=["ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"]
ordine=[0, 2, 4, 6, 3, 8, 5, 7, 1, 9]
def Trova(m, c):
	m_c=[0]*30
	for i in c: m_c[ord(i) - ord('A')]+=1
	for j in range(30): 
		if m_c[j] > m[j]: return False
	return True
	
def Togli(m, c):
	for i in c: m[ord(i)-ord('A')] -= 1

for i in range(int(input())):
	S=input()
	t=[]
	m=[0]*30
	for j in S: m[ord(j) - ord('A')]+=1
	for j in ordine:
		while Trova(m, num[j]):
			t.append(j)
			Togli(m, num[j])
	
	t.sort()
	if sum([len(num[k]) for k in t]) != len(S): print("ERRORE")
	print("Case #%d: %s" %(i+1, "".join([str(j) for j in t])))
