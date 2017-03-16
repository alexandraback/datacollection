def possible(keybs,word):
	for c in word:
		if c not in keybs:
			return False
	return True

def get_start_suffix(word):
	L=len(word)
	index=L
	for start in range(1,L):
		if word[start:]==word[:L-start]:
			index=start
			break
	return index

def get_max(word):
	#compute max
	index=get_start_suffix(word)

	L=len(word)
	count_max=0
	start=0
	while start+L<=S:
		count_max+=1
		start+=index
	return count_max

def get_prev(word,c,prev):
	res=0
	sub=word[:prev]+str(c) #substring
	for l in range(1,min(len(sub)+1,len(word)+1)):
		if sub[-l:]==word[:l]:
			res=l
	return res
	
def solve(S,keybs,word,K,memo,index,prev):
	L=len(word)
	if index==S:
		return 0

	res=memo[index][prev]
	if res is None:
		res=0
		for c in keybs:
			prob=keybs[c]/K
			next_prev=get_prev(word,c,prev)
			count=1 if next_prev==len(word) else 0
			res+=prob*(count+solve(S,keybs,word,K,memo,index+1,next_prev))
		memo[index][prev]=res
	return res


def get_expected(S,keybs,word,K):
	memo=[[None]*(len(word)+1) for i in range(S+1)]
	return solve(S,keybs,word,K,memo,0,0)

def get_keybs(keyb):
	keybs={}
	for c in keyb:
		if c not in keybs:
			keybs[c]=0
		keybs[c]+=1
	return keybs

T=int(input())
for t in range(1,T+1):
	K,L,S=map(int,input().split())
	keyb=input()
	word=input()
	keybs=get_keybs(keyb)

	if not possible(keybs,word):
		print("Case #%d: %f"%(t,0))
		continue

	count_max=get_max(word)
	expected=get_expected(S,keybs,word,K)
	print("Case #%d: %f"%(t,count_max-expected))
	
	




