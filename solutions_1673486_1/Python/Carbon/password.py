T=int(raw_input())
for repeat in xrange(T):
	line_n=raw_input().split()
	A,B=int(line_n[0]),int(line_n[1])
	line_p=raw_input().split()
	p=[]
	for sp in line_p:
		p.append(float(sp))
	product_p=[]
	product=1
	for i in xrange(len(p)):
		product*=p[i]
		product_p.append(product)
	expected=[]
	for i in xrange(len(product_p)):
		p_correct=product_p[len(product_p)-1-i]
		expected.append(p_correct*(B-A+1)+(1-p_correct)*(2*B-A+2)+2*i)
	expected.append(B+2)
	print "Case #%d:"%(repeat+1),"%f"%min(expected)
