n=[]
f = open('4.out','w')
fin = open('4.in','r')
t=int(fin.readline().strip())
for i in range(t):
	n.append(map(lambda x: int(x),fin.readline().strip().split()))
fin.close()

def ceil(b,d):
	if b%d==0:
		return b/d
	else:
		return b/d+1


def calc(k,c,tiles):

	if k<=c:
		ignore=0
		i=1
		chunk=chunkSize=pow(k,c-1)
		while i<=k:
			ignore=ignore+(i-1)*chunk
			chunk=chunk/k
			i=i+1
		
		tiles.append(ignore+1)

	else:
		chunkSize=pow(k,c-1)
		j=1
		while(len(tiles)<ceil(k,c)):
			r=range(len(tiles)*chunkSize+1,len(tiles)*chunkSize+1)
			i=1
			chunk=chunkSize
			ignore=0
			while(i<=c and j<=k):
				ignore=ignore+(j-1)*chunk
				chunk=chunk/k
				i=i+1
				j=j+1
			tiles.append(ignore+1)
			#current=current+chunkSize
	


for i in range(t):
	k=n[i][0]
	c=n[i][1]
	s=n[i][2]
	tiles=[]
	result = "Case #"+str(i+1)+": "
	if(ceil(k,c)<=s):
		calc(k,c,tiles);
		result=result+' '.join(map(lambda x:str(x),tiles))
	else:
		result=result+"IMPOSSIBLE"
	f.write(result+'\n')
	print result

	


	
f.close()