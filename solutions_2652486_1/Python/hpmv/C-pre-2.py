
freq = {}
for i in xrange(4**12):
	k = []
	p = 1
	for j in range(12):
		k.append(i%4)
		p*=[3.0/7,2.0/7,1.0/7,1.0/7][i%4]
		i/=4
	k=sorted(k)
	k=''.join(str(i) for i in k)
	if k in freq:
		freq[k]+=p
	else:
		freq[k]=p
print "freq2=",freq
xs = [x for x in freq]
print "xs2=",xs

ks = {}
kxs = [{} for x in xs]
j=0
for x in xs:
	vals = [[]]
	for i in x:
		vals=[y+[int(i)] for y in vals]+vals

	for val in vals:
		k = sum(val)
		if k in ks:
			ks[k]+=1
		else:
			ks[k]=1
		if k in kxs[j]:
			kxs[j][k]+=1
		else:
			kxs[j][k]=1
	j+=1

print "ks2=",ks
print "kxs2=", kxs


freq = {}
for i in xrange(2**12):
	k = []
	p = 1
	for j in range(12):
		k.append(i%2)
		p*=[5.0/7,2.0/7][i%2]
		i/=4
	k=sorted(k)
	k=''.join(str(i) for i in k)
	if k in freq:
		freq[k]+=p
	else:
		freq[k]=p
print "freq3=",freq
xs = [x for x in freq]
print "xs3=",xs

ks = {}
kxs = [{} for x in xs]
j=0
for x in xs:
	vals = [[]]
	for i in x:
		vals=[y+[int(i)] for y in vals]+vals

	for val in vals:
		k = sum(val)
		if k in ks:
			ks[k]+=1
		else:
			ks[k]=1
		if k in kxs[j]:
			kxs[j][k]+=1
		else:
			kxs[j][k]=1
	j+=1

print "ks3=",ks
print "kxs3=", kxs




freq = {}
for i in xrange(2**12):
	k = []
	p = 1
	for j in range(12):
		k.append(i%2)
		p*=[6.0/7,1.0/7][i%2]
		i/=4
	k=sorted(k)
	k=''.join(str(i) for i in k)
	if k in freq:
		freq[k]+=p
	else:
		freq[k]=p
print "freq5=",freq
print "freq7=",freq
xs = [x for x in freq]
print "xs5=",xs
print "xs7=",xs

ks = {}
kxs = [{} for x in xs]
j=0
for x in xs:
	vals = [[]]
	for i in x:
		vals=[y+[int(i)] for y in vals]+vals

	for val in vals:
		k = sum(val)
		if k in ks:
			ks[k]+=1
		else:
			ks[k]=1
		if k in kxs[j]:
			kxs[j][k]+=1
		else:
			kxs[j][k]=1
	j+=1

print "ks5=",ks
print "kxs5=", kxs

print "ks7=",ks
print "kxs7=", kxs

