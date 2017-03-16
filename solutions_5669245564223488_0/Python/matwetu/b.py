#coding:utf8
import sys
result = {
	"fi": "B-small-attempt1.in",
	#"fi": "b.in",
	"fo": "b.out",
	"ct": ""
}
cnt = {}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)

def cuthead(w, h):
	if w and w[0] == h:
		return cuthead(w[1:],h)
	return w

def cuttail(w, t):
	if w and w[-1] == t:
		return cuttail(w[:-1],t)
	return w

def checkvalid(w,bl=[]):
	#print "checkvalid:",w, bl
	if len(w) == 0:
		#print 'chval:ok'
		return True
	d = w[0]
	if d in bl:
		#print 'chval:fail'
		return False
	bl.append(d)
	return checkvalid(cuthead(w,d),bl)

def Check4(ws):
	print "check4", ws
	for w in ws:
		#print 'checking ',w,
		if not checkvalid(w,[]):
			#print 'Fail'
			return False
	print "check4 ok"
	return True
def Check3(ws):
	for i in range(len(ws)):
		w = ws[i]
		if len(set(w)) > 2:
			h = w[0]
			t = w[-1]
			if h == t:
				return False
			ww = cuthead(cuttail(w, t), h)
			others = ''.join(ws[:i] + ws[i+1:])
			for j in set(ww):
				if j in others:
					return False
	print "check3 ok"
	return True


def Check2(ws):
	h = {}
	t = {}
	for w in ws:
		if len(set(w)) >= 2:
			if w[0] in h:
				return False
			if w[-1] in t:
				return False
			h[w[0]] = 1
			t[w[-1]] = 1
	print "check2 ok"
	return True

def Check1(ws):
	for w in ws:
		if len(set(w)) == 1:
			cnt[w[0]] = 1 if w[0] not in cnt else cnt[w[0]]+1
	for k in cnt:
		cnt[k] = reduce(lambda a,b:a*b,range(1,1+cnt[k]))
	print "cnt:",cnt
	return True
def ishead(ws, w):
	if len(set(w)) == 1:
		return False
	for ww in ws:
		if len(set(ww))>1 and ww[-1] == w[0]:
			return False
	return True


fix = 0

def calc(ws,w):
	global fix
	fix += 1
	p = 1
	if w[0] in cnt:
		p*=cnt[w[0]]
	haveson = False
	for ww in ws:
		if len(set(ww))>2:
			if ww[0] == w[-1]:
				haveson = True
				p*= calc(ws,ww)
	if not haveson:
		if w[-1] in cnt:
			p*=cnt[w[-1]]
	return p

def alone(ws,w):
	print "al0ne ",w
	for ww in ws:
		if len(set(ww))>1 and w in ww:
			print "fail at", ww
			return False
	return True

def checkfix(ws):
	return len(filter(lambda x:len(set(x))>1,ws)) == fix
def Count(ws):
	blocks = []
	for w in ws:
		if ishead(ws,w):
			print w ,'is head'
			blocks.append(calc(ws,w))
	if not checkfix(ws):
		return 0
	for w in cnt:
		if alone(ws,w):
			print w ,"is alone"
			blocks.append(cnt[w])
	print "blocks:",blocks
	tt = zip(blocks, range(1,len(blocks)+1))
	return reduce(lambda a,b:a*b, map(lambda x:x[0]*x[1], tt))



def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		global cnt,fix
		cnt = {}
		fix = 0
		m = int(lines.pop())
		words = lines.pop().strip().split(' ')
		print words
		myprint("Case #%d: " % i)
		if Check4(words) and Check3(words) and Check2(words) and Check1(words):
			myprint("%d\n" % Count(words))
		else:
			myprint("0\n")
	with open(result['fo'], 'w') as f:
		f.write(result['ct'])

def test():
	print checkvalid('')
if __name__ == '__main__':
	main()