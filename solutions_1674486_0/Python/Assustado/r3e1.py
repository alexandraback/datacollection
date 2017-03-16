def encontra_todos_caminhos(grafo, inicio, fim, caminho=[]):
    caminho = caminho + [inicio]
    if inicio == fim:
        return [caminho]
    if not grafo.has_key(inicio):
        return []
    caminhos = []
    for vertice in grafo[inicio]:
        if vertice not in caminho:
            novos_caminhos = encontra_todos_caminhos(grafo, vertice, fim, caminho)
            for novo_caminho in novos_caminhos:
                caminhos.append(novo_caminho)
    return caminhos 
f=open("teste","r")
pika=f.read()
pika=pika.split()
t=int(pika.pop(0))
o=0
while t!=0:
        o=o+1
        t=t-1
	n=int(pika.pop(0))
	i=0
	d={}
	i=0
	while i<n:
		g=[]
		p=0
		i=i+1
		k=int(pika.pop(0))
		while p<k:
			g=g+[int(pika.pop(0))]
			p=p+1
		d[i]=g
	i=0
	flag=0
	##print d
	while i<n:
		i=i+1
		p=0
		while p<n:
			p=p+1
			##print i,p,n
			if len(encontra_todos_caminhos(d,i,p))>1:
				flag=1
				break
		if flag==1:
			break
        q=open("resp","a")
        q.write("Case #"+str(o)+": ")
	if flag==1:
		q.write("Yes")
	else:
		q.write("No")
	q.write("\n")
