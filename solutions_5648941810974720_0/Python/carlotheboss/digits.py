num=["ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"]
def Trova(S, c):
	m,m_c=[0]*30,[0]*30
	for i in c: m_c[ord(i) - ord('A')]+=1
	for i in S: 
		if i != '#': 
			m[ord(i) - ord('A')]+=1
	ok=True
	for j in range(30): 
		if m_c[j] > m[j]: ok=False
	
	return ok
	
def Togli(S, c):
	m=[0]*30
	for i in c: m[ord(i)-ord('A')]+=1
	nuova=""
	for i in S:
		if m[ord(i)-ord('A')] > 0:
			nuova+="#"
			m[ord(i) - ord('A')]-=1
		else:
			nuova+=i
	
	return nuova

def F(s, last_num):
	#print("Cerco %d in %s" %(last_num, s))
	for i in range(last_num, 10):	
		if Trova(s, num[i]):
			#print("\tmetto %d per %s" %(i, s))
			tmp=[]
			tmp.append(i)
			tmp += F(Togli(s, num[ i ]), i)
			#print("Ho %s" %("".join([str(j) for j in tmp])))
			somma = sum([len(num[k]) for k in tmp])
			if somma==len(s) - s.count('#'): 
				return tmp
	#print("Fine")
	return []

for i in range(int(input())):
	S=input()
	t=F(S, 0)
	if sum([len(num[k]) for k in t]) != len(S): print("ERRORE")
	print("Case #%d: %s" %(i+1, "".join([str(j) for j in t])))
