#with open("A-small-attempt0.in") as f:
with open("A-large.in") as f:
#with open("test.in") as f:
	dat = f.readlines()

def remove(d,word,n):
	for w in list(word):
		d = d.replace(w,"",n)
	return d

def special(d,s,sn,word,res):
	n = d.count(s)
	res += sn*n
	d = remove(d,word,n)
	return d,res
	
n = int(dat[0])
out = []
for i in range(1,n+1):
	d = dat[i].replace("\n","")
	
	res = ""
	d,res = special(d,"Z","0","ZERO",res)
	d,res = special(d,"W","2","TWO",res)
	d,res = special(d,"X","6","SIX",res)
	d,res = special(d,"G","8","EIGHT",res)
	d,res = special(d,"H","3","THREE",res)
	d,res = special(d,"R","4","FOUR",res)
	d,res = special(d,"F","5","FIVE",res)
	d,res = special(d,"S","7","SEVEN",res)
	d,res = special(d,"I","9","NINE",res)
	d,res = special(d,"O","1","ONE",res)
	
	#print(d)
	assert d == ""
	res = list(res)
	res.sort()
	res = "".join(res)
	res = "Case #"+str(i)+": "+res
	print(res)
	out.append(res)
	
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



