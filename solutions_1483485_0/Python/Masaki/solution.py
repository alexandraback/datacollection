def decode(x):
	english={' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}
	s=""
	for i in range(0,len(x)):
		s=s+english[x[i]]
	return(s)

xy=input("filename\n")
hjs=open(xy,"r")
g=int((hjs.readline()).strip())
hjk=open("speaking in tongues.txt","w")
for i in range(1,g+1):
	gh=(hjs.readline()).strip()
	jnk=decode(gh)
	hjk.write("Case #"+str(i)+":"+" "+jnk+"\n")
hjs.close()
hjk.close()