
i=open('input','r')
o=open('output','r')

h=i.readline()

ils=""
for l in i:
	ils+=l

ols=""
for l in o:
	ols+=l[9:]

mapping={}

for idx,val in enumerate(ils):
	if 'a'<=val and val<='z':
		mapping[val]=ols[idx]

for k,v in mapping.items():
	print k,v

