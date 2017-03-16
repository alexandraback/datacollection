

T=int(input())

for case in range(1,T+1):
	feed=list(input())
	myword=[feed[0]]
	for let in feed[1:]:
		if let>=myword[0]:
			myword.insert(0,let)
		else:
			myword.append(let)
	string="".join(myword)

	print("Case #%d: %s" %(case,string) )