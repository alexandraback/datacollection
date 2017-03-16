from fractions import gcd

T = int(input())
i = 0

pprint = print
def gprint (*args, **kwargs):
	global i

	pprint ("Case #{}:".format(i+1), *args, **kwargs)

print = gprint


for i in range (T):
	a, b = [int(x) for x in input().strip().split("/")]
	a, b = a/gcd(a, b), b/gcd(a, b)

	moc = 1

	while (b > 1) :
		if (b%2 != 0 ):
			moc = -1
			break

		moc += 1
		b /= 2

	if moc == -1 : 
		print ("impossible")
		continue

	while (a >= 1):
		moc -= 1
		a /= 2


	print (moc)